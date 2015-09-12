#include "parser.h"

Parser::Parser(Lexer *lexer)
{
    this->lexer=lexer;
    ConsumeToken();
}

void Parser::ConsumeToken()
{
    currenttoken = lexer->GetToken();
    currenttoken->Print();
}

void Parser::Parse()
{
    Programa();
    if (currenttoken->type != EOFi)
    {
           throw invalid_argument("Se esperaba EOF.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    }
}
void Parser::Programa()
{
    if(currenttoken->type == HTML)
    {
        ConsumeToken();
        Programa();
    }
    else if(currenttoken->type != HTML && currenttoken->type != EOFi)
    {
        ProgramaLpp();
        Programa();
    }
    else
    {
        //Epsilon
    }
}

void Parser::ProgramaLpp()
{
    InstructionList();
    RegisterDeclarations();
    VariableDeclarations();
    FunctionDeclarations();
}
void Parser::FunctionDeclarations()
{
    if(currenttoken->type == Funcion || currenttoken->type == Procedimiento)
    {
        FunctionDeclaration();
        FunctionDeclarations();
    }
    else
    {
        //Epsilon
    }
}
void Parser::RegisterDeclarations()
{
    if(currenttoken->type == Registro || currenttoken->type == Tipo)
    {
        RegisterDeclaration();
        RegisterDeclarations();
    }
    else
    {
        //Epsilon
    }
}
void Parser::RegisterDeclaration()
{
    if(currenttoken->type == Registro)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        VariableDeclarations();
        if(currenttoken->type != Fin)
                throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Registro)
            throw invalid_argument("Se esperaba palabra reservada Registro.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else if(currenttoken->type == Tipo)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Es)
                throw invalid_argument("Se esperaba palabra reservada es.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        Type();
    }
}

void Parser::FunctionDeclaration()
{
    if(currenttoken->type == Funcion || currenttoken->type == Procedimiento)
    {
        FunctionHeader();
        VariableDeclarations();
        if(currenttoken->type != Inicio)
                throw invalid_argument("Se esperaba palabra reservada inicio.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        InstructionList();
        if(currenttoken->type != Fin)
                throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else
    {
        //Epsilon
    }
}
void Parser::FunctionHeader()
{
    if(currenttoken->type == Funcion)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        FunctionArguments();
        if(currenttoken->type != Colon)
            throw invalid_argument("Se esperaba :.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        Type();
    }
    else if(currenttoken->type == Procedimiento)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        FunctionArguments();
    }
}
void Parser::FunctionArguments()
{
    if(currenttoken->type == OpenParenthesis)
    {
        ConsumeToken();
        ParameterList();
        if(currenttoken->type != CloseParenthesis)
                throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else
    {
        //Epsilon
    }


}
void Parser::ParameterList()
{
    if(currenttoken->type == ParameterVariable || IsType(currenttoken) )
    {
        ParameterDeclaration();
        ParameterListPrime();
    }
    else
    {
        //Epsilon
    }
}
void Parser::ParameterDeclaration()
{
    if(currenttoken->type == ParameterVariable)
    {
        ConsumeToken();
        Type();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else
    {
        Type();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
}
void Parser::ParameterListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        ParameterDeclaration();
        ParameterListPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::InstructionList()
{
    if(IsInstruccion(currenttoken))
    {
        Instruction();
        InstructionList();
    }
    else
    {
        //Epsilon
    }
}

void Parser::Instruction()
{
    if(currenttoken->type == Si)
    {
        SiInstruction();
    }
    else if(currenttoken->type == Para)
    {
        ParaInstruction();
    }
    else if(currenttoken->type == Id)
    {
        ValueAllocInstruction();
    }
    else if(currenttoken->type == Escriba)
    {
        EscribaInstruction();
    }
    else if(currenttoken->type == Mientras)
    {
        MientrasInstruction();
    }
    else if(currenttoken->type == Repita)
    {
        RepitaInstruction();
    }
    else if(currenttoken->type == Caso)
    {
        CasoInstruction();
    }
    else if(currenttoken->type == Abrir)
    {
        AbrirArchiveInstruction();
    }
    else if(currenttoken->type == Cerrar)
    {
        CerrarArchiveInstruction();
    }
    else if(currenttoken->type == Leer)
    {
        LeerArchiveInstruction();
    }
    else if(currenttoken->type == Escribir)
    {
        EscribirArchiveInstruction();
    }
    else if(currenttoken->type == Llamar)
    {
        LlamarInstruction();
    }
    else if(currenttoken->type == Retorne)
    {
        RetorneInstruction();
    }
}
void Parser::SiInstruction()
{
        ConsumeToken();
        Expresion();
        if(currenttoken->type != Entonces)
            throw invalid_argument("Se esperaba palabra reservada entonces.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        InstructionList();
        SiInstructionPrime();
}
void Parser::Expresion()
{
    ExpresionInequalities();
    ConditionalExpresion();
}
void Parser::ExpresionInequalities()
{
    SubExpresion();
    ExpresionInequalitiesPrime();
}
void Parser::SubExpresion()
{
    Term();
    SubExpresionPrime();
}
void Parser::Term()
{
    Power();
    TermPrime();
}
void Parser::Negated()
{
    Factors();
    NegatedPrime();
}
void Parser::Power()
{
    Negated();
    PowerPrime();
}
void Parser::Factors()
{
    if(currenttoken->type == Id)
            Variable();
    else if(currenttoken->type == OpenParenthesis){
            ConsumeToken();
            Expresion();
            if(currenttoken->type != CloseParenthesis)
                throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
            ConsumeToken();
    }
    else if(IsLiteral(currenttoken))
    {
        Literal();
    }
    else if(currenttoken->type == Verdadero)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == Falso)
    {
        ConsumeToken();
    }

}
void Parser::PowerPrime()
{
    if(currenttoken->type == Exponentiation)
    {
        ConsumeToken();
        Negated();
        PowerPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::NegatedPrime()
{
    if(currenttoken->type == No)
    {
        ConsumeToken();
        Factors();
        NegatedPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::TermPrime()
{
    if(currenttoken->type == Multiplication)
    {
        ConsumeToken();
        Power();
        TermPrime();
    }
    else if(currenttoken->type == RealDivision)
    {
        ConsumeToken();
        Power();
        TermPrime();
    }
    else if(currenttoken->type == IntegerDivision)
    {
        ConsumeToken();
        Power();
        TermPrime();
    }
    else if(currenttoken->type == Mod)
    {
        ConsumeToken();
        Power();
        TermPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::SubExpresionPrime()
{
    if(currenttoken->type == Sum)
    {
        ConsumeToken();
        Term();
        SubExpresionPrime();
    }
    else if(currenttoken->type == Substraction)
    {
        ConsumeToken();
        Term();
        SubExpresionPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::ExpresionInequalitiesPrime()
{
    if(currenttoken->type == GreaterThan)
    {
        ConsumeToken();
        SubExpresion();
    }
    else if(currenttoken->type == LessThan)
    {
        ConsumeToken();
        SubExpresion();
    }
    else if(currenttoken->type == GreaterEqual)
    {
        ConsumeToken();
        SubExpresion();
    }
    else if(currenttoken->type == LessEqual)
    {
        ConsumeToken();
        SubExpresion();
    }
    else if(currenttoken->type == Equal)
    {
        ConsumeToken();
        SubExpresion();
    }
    else if(currenttoken->type == NotEqual)
    {
        ConsumeToken();
        SubExpresion();
    }
    else
    {
        //Epsilon
    }
}

void Parser::ConditionalExpresion()
{
    if(currenttoken->type == Or)
    {
        ConsumeToken();
        Expresion();
    }
    else if(currenttoken->type == And)
    {
        ConsumeToken();
        Expresion();
    }
    else
    {
        //Epsilon
    }
}

void Parser::SiInstructionPrime()
{
    if(currenttoken->type == Fin)
    {
        ConsumeToken();
        if(currenttoken->type != Si)
            throw invalid_argument("Se esperaba palabra reservada si.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }else if(currenttoken->type == Sino)
    {
        ConsumeToken();
        InstructionList();
        if(currenttoken->type != Fin)
            throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Si)
            throw invalid_argument("Se esperaba palabra reservada si.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
}

void Parser::ParaInstruction()
{
    ConsumeToken();
    Variable();
    if(currenttoken->type != ValueAllocation)
        throw invalid_argument("Se esperaba <-.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Expresion();
    if(currenttoken->type != Hasta)
        throw invalid_argument("Se esperaba palabra reservada hasta.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Expresion();
    if(currenttoken->type != Haga)
        throw invalid_argument("Se esperaba palabra reservada haga.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    InstructionList();
    if(currenttoken->type != Fin)
        throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    if(currenttoken->type != Para)
        throw invalid_argument("Se esperaba palabra reservada para.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
}
void Parser::ValueAllocInstruction()
{
    Variable();
    if(currenttoken->type != ValueAllocation)
        throw invalid_argument("Se esperaba <-.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Expresion();
}
void Parser::EscribaInstruction()
{
    ConsumeToken();
    ExpressionListNotNull();
}
void Parser::MientrasInstruction()
{
    ConsumeToken();
    Expresion();
    if(currenttoken->type != Haga)
        throw invalid_argument("Se esperaba palabra reservada haga.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    InstructionList();
    if(currenttoken->type != Fin)
        throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    if(currenttoken->type != Mientras)
        throw invalid_argument("Se esperaba palabra reservada mientras.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
}
void Parser::RepitaInstruction()
{
    ConsumeToken();
    InstructionList();
    if(currenttoken->type != Hasta)
        throw invalid_argument("Se esperaba palabra reservada hasta.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Expresion();
}
void Parser::CasoInstruction()
{
    ConsumeToken();
    Variable();
    CasoList();
    CasoSino();
    if(currenttoken->type != Fin)
        throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    if(currenttoken->type != Caso)
        throw invalid_argument("Se esperaba palabra reservada caso.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
}
void Parser:: CasoList()
{
        CasoLine();
        CasoListPrime();
}
void Parser::CasoLine()
{
    LiteralList();
    if(currenttoken->type != Colon)
        throw invalid_argument("Se esperaba :.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    InstructionList();
}

void Parser::LiteralList()
{
    Literal();
    LiteralListPrime();
}

void Parser::Literal()
{
    if(currenttoken->type == EnteroNumber)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == RealNumber)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == Substraction)
    {
        ConsumeToken();
        if(!IsLiteralNumber(currenttoken))
            throw invalid_argument("Se esperaba un numero entero o real.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else if(currenttoken->type == Character)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == Str)
    {
        ConsumeToken();
    }
}



void Parser::LiteralListPrime()
{
    if(currenttoken->type==Coma)
    {
        LiteralList();
    }
    else
    {
        //Epsilon
    }
}

void Parser::CasoListPrime()
{
    if(IsLiteral(currenttoken))
    {
        CasoList();
    }
    else
    {
        //Epsilon
    }
}

void Parser:: CasoSino()
{
    if(currenttoken->type == Sino){
            ConsumeToken();
            if(currenttoken->type != Colon)
                throw invalid_argument("Se esperaba :.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
            ConsumeToken();
            InstructionList();
        }else{
            //Epsilon
        }
}

void Parser::AbrirArchiveInstruction()
{
    ConsumeToken();
    Archive();
    if(currenttoken->type != Como)
        throw invalid_argument("Se esperaba palabra reservada como.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Variable();
    ModeList();
}
void Parser::Archive()
{
    if(currenttoken->type == Str)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == Id)
    {
        ConsumeToken();
    }
    else
    {
        throw invalid_argument("Se esperaba Id o String.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    }
}

void Parser::ModeList()
{
    if(currenttoken->type == Para)
    {
        ConsumeToken();
        Mode();
        ModeListPrime();
    }
    else
    {
        //Epsilon
    }
}
void Parser::Mode()
{
    if(currenttoken->type == Escritura)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == Lectura)
    {
        ConsumeToken();
    }
}
void Parser::ModeListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        Mode();
    }
    else
    {
        //Epsilon
    }
}

void Parser::CerrarArchiveInstruction()
{
    ConsumeToken();
    Variable();
}
void Parser::LeerArchiveInstruction()
{
    ConsumeToken();
    Variable();
    if(currenttoken->type != Coma)
        throw invalid_argument("Se esperaba ,.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Variable();
}
void Parser::EscribirArchiveInstruction()
{
    ConsumeToken();
    Variable();
    if(currenttoken->type != Coma)
        throw invalid_argument("Se esperaba ,.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Variable();
}
void Parser::LlamarInstruction()
{
    ConsumeToken();
    if(currenttoken->type != Id)
        throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    Parameters();
}
void Parser::Parameters()
{
    if(currenttoken->type == OpenParenthesis)
    {
        ConsumeToken();
        ExpresionListNull();
        if(currenttoken->type != CloseParenthesis)
            throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else
    {
        //Epsilon
    }
}
void Parser::ExpresionListNull()
{
    if(currenttoken->type != CloseParenthesis)
    {
        Expresion();
        ExpresionListNotNullPrime();
    }
}

void Parser::ExpressionListNotNull()
{
    Expresion();
    ExpresionListNotNullPrime();
}
void Parser::ExpresionListNotNullPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        Expresion();
        ExpresionListNotNullPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::RetorneInstruction()
{
   ConsumeToken();
    Variable();
}
void Parser::Variable()
{
    if(currenttoken->type != Id)
        throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    VariablePrime();
}



void Parser::VariablePrime()
{
    if(currenttoken->type == OpenParenthesis)
    {
        ConsumeToken();
        ExpresionListNull();
        if(currenttoken->type != CloseParenthesis)
            throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else
    {
        AccesorList();
    }
}

void Parser::AccesorList()
{
    if(currenttoken->type == Period)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        AccesorList();
    }
    else if(currenttoken->type == OpenBracket)
    {
        ConsumeToken();
        ExpressionListNotNull();
        if(currenttoken->type != CloseBracket)
            throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        AccesorList();
    }
    else
    {
        //Epsilon
    }
}


void Parser::VariableDeclarations()
{
    if(currenttoken->type == DECLARAR){
        ConsumeToken();
        DeclarationLine();
        VariableDeclarations();
    }
    else
    {
        //Epsilon
    }

}
void Parser::DeclarationLine()
{
    Type();
    IdList();

}

void Parser::IdList()
{
    if(currenttoken->type != Id)
        throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    IdListPrime();
}
void Parser::IdListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        if(currenttoken->type!=Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        IdListPrime();
    }
    else
    {
        //Epsilon
    }
}

void Parser::Type()
{
    if(currenttoken->type == Id)
    {
        ConsumeToken();
    }
    else if(currenttoken->type == Arreglo)
    {
        ConsumeToken();
        if(currenttoken->type != OpenBracket)
            throw invalid_argument("Se esperaba [.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        IntList();
        if(currenttoken->type != CloseBracket)
            throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != De)
            throw invalid_argument("Se esperaba palabra reservada de.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        Type();
    }

    else if(currenttoken->type == Entero)
        ConsumeToken();

    else if(currenttoken->type == Real)
        ConsumeToken();
    else if(currenttoken->type == Booleano)
        ConsumeToken();
    else if(currenttoken->type == Caracter)
        ConsumeToken();
    else if(currenttoken->type == Archivo)
    {
        ConsumeToken();
        ArchiveType();
    }
    else if(currenttoken->type == Cadena)
    {
        ConsumeToken();
        if(currenttoken->type != OpenBracket)
            throw invalid_argument("Se esperaba [.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != EnteroNumber )
            throw invalid_argument("Se esperaba numero entero.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != CloseBracket)
            throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();

    }
    /*else
        throw invalid_argument("Se esperaba un tipo de dato.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    */
}
void Parser::IntList()
{
    if(currenttoken->type != EnteroNumber)
        throw invalid_argument("Se esperaba numero entero.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    IntListPrime();
}
void Parser::IntListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        if(currenttoken->type != EnteroNumber)
            throw invalid_argument("Se esperaba numero entero.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
    }
    else
    {
        //Epsilon
    }
}

void Parser:: ArchiveType()
{
    if(currenttoken->type == De)
    {
        ConsumeToken();
        Type();
    }
    else if (currenttoken->type == Secuencial)
        ConsumeToken();
}

bool Parser::IsInstruccion(Token * token){
   if(token->type == Si || token->type == Para || token->type == Id  || token->type == Escriba ||token->type == Mientras
   ||token->type == Repita || token->type == Caso || token->type == Abrir || token->type == Cerrar
   ||token->type == Llamar || token->type ==Escribir || token->type == Leer || token->type == Retorne)
        return true;
   return false;
}
bool Parser::IsLiteral(Token * token)
{
    if(token->type == EnteroNumber || token->type == RealNumber
    ||token->type == Character || token->type ==Str)
         return true;
    return false;
}
bool Parser::IsLiteralNumber(Token * token)
{
    if(token->type == EnteroNumber || token->type == RealNumber)
         return true;
    return false;
}
bool Parser::IsType(Token * token)
{
    if(token->type == Entero || token->type == Real || token->type == Arreglo || token->type == Cadena
       || token->type == Booleano || token->type == Caracter || token->type == Archivo || token->type == Id)
        return true;
    return false;

}


string Parser::to_string(int tostring)
{
    ostringstream stm ;
    stm << tostring ;
    return stm.str() ;
}
Parser::~Parser()
{

}



