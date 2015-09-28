#include "parser.h"

Parser::Parser(Lexer *lexer)
{
    this->lexer=lexer;
    ConsumeToken();
}

void Parser::ConsumeToken()
{
    currenttoken = lexer->GetToken();
    //currenttoken->Print();
}

vector<StatementNode*> Parser::Parse()
{
    vector<StatementNode*> list = Programa();
    if (currenttoken->type != EOFi)
    {
           throw invalid_argument("Se esperaba EOF.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    }
    return list;
}
vector<StatementNode*> Parser::Programa()
{
    if(currenttoken->type == HTML)
    {
        string html=currenttoken->lexeme;
        ConsumeToken();
        vector<StatementNode*>list=Programa();
        list.insert(list.begin(),new HTMLNode(html));
        return list;
    }
    else if(currenttoken->type != HTML && currenttoken->type != EOFi)
    {
        vector<StatementNode*> statements =ProgramaLpp();
        vector<StatementNode*>list=Programa();

        for(unsigned int i=0;i<statements.size();i++)
            list.insert(list.begin(),statements.at(i));
        return list;
    }
    else
    {
        vector<StatementNode*> list;
        return list;
    }
}

vector<StatementNode *> Parser::ProgramaLpp()
{
    vector<StatementNode*> statements;

    statements=InstructionList();
    if(statements.size()!=0)
    {
        reverse(statements.begin(),statements.end());
        return statements;
    }
    statements=RegisterDeclarations();
    if(statements.size()!=0)
    {
        reverse(statements.begin(),statements.end());
        return statements;
    }
    statements=VariableDeclarations();
    if(statements.size()!=0)
    {
        reverse(statements.begin(),statements.end());
        return statements;
    }
    statements=FunctionDeclarations();
    if(statements.size()!=0)
    {
        reverse(statements.begin(),statements.end());
        return statements;
    }
    return statements;
}
vector<StatementNode*> Parser::FunctionDeclarations()
{
    if(currenttoken->type == Funcion || currenttoken->type == Procedimiento)
    {
        StatementNode * function = FunctionDeclaration();
        vector<StatementNode*> list =FunctionDeclarations();
        list.insert(list.begin(),function);
        return list;
    }
    else
    {
        vector<StatementNode*>list;
        return list;
    }
}
vector<StatementNode*>Parser::RegisterDeclarations()
{
    if(currenttoken->type == Registro || currenttoken->type == Tipo)
    {
        StatementNode * statement = RegisterDeclaration();
        vector <StatementNode*> list=RegisterDeclarations();
        list.insert(list.begin(),statement);
        return list;
    }
    else
    {
        vector<StatementNode*> list;
        return list;
    }
}
StatementNode* Parser::RegisterDeclaration()
{
    if(currenttoken->type == Registro)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));

        string id= currenttoken->lexeme;
        ConsumeToken();
        vector<StatementNode*> variables=VariableDeclarations();
        if(currenttoken->type != Fin)
                throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Registro)
            throw invalid_argument("Se esperaba palabra reservada Registro.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new RegistroNode(id,variables);
    }
    else if(currenttoken->type == Tipo)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id=currenttoken->lexeme;
        ConsumeToken();
        if(currenttoken->type != Es)
                throw invalid_argument("Se esperaba palabra reservada es.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        TypeNode* type=Type();
        return new TipoNode(id,type);
    }
}

StatementNode* Parser::FunctionDeclaration()
{
    if(currenttoken->type == Funcion)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string idFunction = currenttoken->lexeme;
        ConsumeToken();
        vector<ParameterNode*> parameters=FunctionArguments();

        if(currenttoken->type != Colon)
            throw invalid_argument("Se esperaba :.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        TypeNode * typeFunction =Type();

        vector<StatementNode*> variables=VariableDeclarations();
        if(currenttoken->type != Inicio)
                throw invalid_argument("Se esperaba palabra reservada inicio.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<StatementNode*> instList=InstructionList();
        if(currenttoken->type != Fin)
                throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new FuncionNode(idFunction,typeFunction,parameters,variables,instList);
    }
    else if(currenttoken->type == Procedimiento)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
                throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id=currenttoken->lexeme;
        ConsumeToken();
        vector<ParameterNode*> parameters=FunctionArguments();

        vector<StatementNode*> variables=VariableDeclarations();
        if(currenttoken->type != Inicio)
                throw invalid_argument("Se esperaba palabra reservada inicio.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<StatementNode*>instList=InstructionList();
        if(currenttoken->type != Fin)
                throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new ProcedimientoNode(id,parameters,variables,instList);
    }
}

vector<ParameterNode*> Parser::FunctionArguments()
{
    if(currenttoken->type == OpenParenthesis)
    {
        ConsumeToken();
        vector<ParameterNode*> list=ParameterList();
        if(currenttoken->type != CloseParenthesis)
                throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return list;
    }
    else
    {
        vector<ParameterNode*>list;
        return list;
    }


}
vector<ParameterNode*> Parser::ParameterList()
{
    if(currenttoken->type == ParameterVariable || IsType(currenttoken) )
    {
        ParameterNode * parameter =ParameterDeclaration();
        vector<ParameterNode*> list =ParameterListPrime();
        list.insert(list.begin(),parameter);
        return list;
    }
    else
    {
        vector<ParameterNode*> list;
        return list;
    }
}
ParameterNode* Parser::ParameterDeclaration()
{
    if(currenttoken->type == ParameterVariable)
    {
        ConsumeToken();
        TypeNode * type=Type();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id=currenttoken->lexeme;
        ConsumeToken();
        return new ReferenceParameterNode(id,type);
    }
    else
    {
        TypeNode * type=Type();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id=currenttoken->lexeme;
        ConsumeToken();
        return new SimpleParameterNode(id,type);
    }
}
vector<ParameterNode*> Parser::ParameterListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        ParameterNode* parameter=ParameterDeclaration();
        vector<ParameterNode*> list=ParameterListPrime();
        list.insert(list.begin(),parameter);
        return list;
    }
    else
    {
        vector<ParameterNode*> list;
        return list;
    }
}

vector<StatementNode*> Parser::InstructionList()
{
    if(IsInstruccion(currenttoken))
    {
        StatementNode* inst=Instruction();
        vector<StatementNode*> list=InstructionList();
        list.insert(list.begin(),inst);
        return list;
    }
    else
    {
        vector<StatementNode*> list;
        return list;
    }
}

StatementNode* Parser::Instruction()
{
    if(currenttoken->type == Si)
    {
        ConsumeToken();
        ExpressionNode* condition=Expresion();
        if(currenttoken->type != Entonces)
            throw invalid_argument("Se esperaba palabra reservada entonces.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<StatementNode*> codeTrue=InstructionList();
        vector<StatementNode*> codeFalse=SiInstructionPrime();
        return new SiNode(condition,codeTrue,codeFalse);
    }
    else if(currenttoken->type == Para)
    {
        ConsumeToken();
        VariableNode * id=Variable();
        if(currenttoken->type != ValueAllocation)
            throw invalid_argument("Se esperaba <-.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        ExpressionNode* value=Expresion();

        if(currenttoken->type != Hasta)
            throw invalid_argument("Se esperaba palabra reservada hasta.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        ExpressionNode* condition = Expresion();
        if(currenttoken->type != Haga)
            throw invalid_argument("Se esperaba palabra reservada haga.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<StatementNode*> code =InstructionList();
        if(currenttoken->type != Fin)
            throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Para)
            throw invalid_argument("Se esperaba palabra reservada para.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new ParaNode(new AssignmentNode(id,value),condition,code);
    }
    else if(currenttoken->type == Id)
    {
        VariableNode* id=Variable();
        if(currenttoken->type != ValueAllocation)
            throw invalid_argument("Se esperaba <-.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        ExpressionNode* expression=Expresion();
        return new AssignmentNode(id,expression);
    }
    else if(currenttoken->type == Escriba)
    {
        ConsumeToken();
        vector<ExpressionNode*> exprList=ExpressionListNotNull();
        return new EscribaNode(exprList);
    }
    else if(currenttoken->type == Mientras)
    {
        ConsumeToken();
        ExpressionNode * condition=Expresion();
        if(currenttoken->type != Haga)
            throw invalid_argument("Se esperaba palabra reservada haga.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<StatementNode*>code=InstructionList();
        if(currenttoken->type != Fin)
            throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Mientras)
            throw invalid_argument("Se esperaba palabra reservada mientras.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new MientrasNode(condition,code);
    }
    else if(currenttoken->type == Repita)
    {
        ConsumeToken();
        vector<StatementNode*> code=InstructionList();
        if(currenttoken->type != Hasta)
            throw invalid_argument("Se esperaba palabra reservada hasta.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        ExpressionNode*condition=Expresion();
        return new RepitaNode(code,condition);
    }
    else if(currenttoken->type == Caso)
    {
        ConsumeToken();
        VariableNode * id=Variable();
        vector<CasoLineNode*> cases=CasoList();
        vector<StatementNode*> defaultcase=CasoSino();
        if(currenttoken->type != Fin)
            throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Caso)
            throw invalid_argument("Se esperaba palabra reservada caso.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new CasoNode(id,cases,defaultcase);
    }
    else if(currenttoken->type == Abrir)
    {
        ConsumeToken();
        string archiveId=Archive();
        if(currenttoken->type != Como)
            throw invalid_argument("Se esperaba palabra reservada como.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        VariableNode* archiveType=Variable();
        vector<ModeNode*> modes=ModeList();
        return new AbrirArchivoNode(archiveId,archiveType,modes);
    }
    else if(currenttoken->type == Cerrar)
    {
        ConsumeToken();
        VariableNode* id= Variable();
        return new CerrarArchivoNode(id);
    }
    else if(currenttoken->type == Leer)
    {
        ConsumeToken();
        VariableNode* archive=Variable();
        if(currenttoken->type != Coma)
            throw invalid_argument("Se esperaba ,.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        VariableNode* data=Variable();
        return new LeerArchivoNode(archive,data);
    }
    else if(currenttoken->type == Escribir)
    {
        ConsumeToken();
        VariableNode* archive=Variable();
        if(currenttoken->type != Coma)
            throw invalid_argument("Se esperaba ,.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        VariableNode* data=Variable();
        return new EscribirArchivoNode(archive,data);
    }
    else if(currenttoken->type == Llamar)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id=currenttoken->lexeme;
        ConsumeToken();
        vector<ExpressionNode*> parameters=Parameters();
        return new LlamarNode(id,parameters);
    }
    else if(currenttoken->type == Retorne)
    {
        ConsumeToken();
        ExpressionNode* id=Expresion();
        return new RetorneNode(id);
    }
}

ExpressionNode* Parser::Expresion()
{
    ExpressionNode * expression =ExpresionInequalities();
    return ConditionalExpresion(expression);
}
ExpressionNode* Parser::ExpresionInequalities()
{
    ExpressionNode *expression=SubExpresion();
    return ExpresionInequalitiesPrime(expression);
}
ExpressionNode* Parser::SubExpresion()
{
    ExpressionNode* expression=Term();
    return SubExpresionPrime(expression);
}
ExpressionNode *Parser::Term()
{
    ExpressionNode * expression=Power();
    return TermPrime(expression);
}
ExpressionNode* Parser::PowerPrime(ExpressionNode*param)
{
    if(currenttoken->type == Exponentiation)
    {
        ConsumeToken();
        ExpressionNode* expression=Negated();
        return PowerPrime(new PowerNode(param,expression));
    }
    else
    {
        return param;
    }
}


ExpressionNode* Parser::TermPrime(ExpressionNode* param)
{
    if(currenttoken->type == Multiplication)
    {
        ConsumeToken();
        ExpressionNode* expression=Power();
        return TermPrime(new MultiplicationNode(param,expression));
    }
    else if(currenttoken->type == RealDivision)
    {
        ConsumeToken();
        ExpressionNode* expression=Power();
        return TermPrime(new DivisionNode(param,expression));
    }
    else if(currenttoken->type == IntegerDivision)
    {
        ConsumeToken();
        ExpressionNode* expression=Power();
        return TermPrime(new DivNode(param,expression));
    }
    else if(currenttoken->type == Mod)
    {
        ConsumeToken();
        ExpressionNode* expression=Power();
        return TermPrime(new ModNode(param,expression));
    }
    else
    {
        return param;
    }
}

ExpressionNode* Parser::SubExpresionPrime(ExpressionNode* param)
{
    if(currenttoken->type == Sum)
    {
        ConsumeToken();
        ExpressionNode* expression=Term();
        return SubExpresionPrime(new SumNode(param,expression));
    }
    else if(currenttoken->type == Substraction)
    {
        ConsumeToken();
        ExpressionNode* expression=Term();
        return SubExpresionPrime(new SubstractionNode(param,expression));
    }
    else
    {
        return param;
    }
}

ExpressionNode* Parser::ExpresionInequalitiesPrime(ExpressionNode* param)
{
    if(currenttoken->type == GreaterThan)
    {
        ConsumeToken();
        ExpressionNode*expression=SubExpresion();
        return new GreaterThanNode(param,expression);
    }
    else if(currenttoken->type == LessThan)
    {
        ConsumeToken();
        ExpressionNode*expression=SubExpresion();
        return new LessThanNode(param,expression);
    }
    else if(currenttoken->type == GreaterEqual)
    {
        ConsumeToken();
        ExpressionNode*expression=SubExpresion();
        return new GreaterEqualNode(param,expression);
    }
    else if(currenttoken->type == LessEqual)
    {
        ConsumeToken();
        ExpressionNode*expression=SubExpresion();
        return new LessEqualNode(param,expression);
    }
    else if(currenttoken->type == Equal)
    {
        ConsumeToken();
        ExpressionNode*expression=SubExpresion();
        return new EqualNode(param,expression);
    }
    else if(currenttoken->type == NotEqual)
    {
        ConsumeToken();
        ExpressionNode*expression=SubExpresion();
        return new NotEqualNode(param,expression);
    }
    else
    {
        return param;
    }
}

ExpressionNode *Parser::ConditionalExpresion(ExpressionNode * param)
{
    if(currenttoken->type == Or)
    {
        ConsumeToken();
        ExpressionNode* expression=Expresion();
        return new OrNode(param,expression);
    }
    else if(currenttoken->type == And)
    {
        ConsumeToken();
        ExpressionNode* expression=Expresion();
        return new AndNode(param,expression);
    }
    else
    {
        return param;
    }
}

ExpressionNode* Parser::Negated()
{
    if(currenttoken->type == No)
    {
        ConsumeToken();
        ExpressionNode* expression =Factors();
        return new NegatedNode(0,expression);
    }
    else
    {
        return Factors();
    }
}
ExpressionNode* Parser::Power()
{
    ExpressionNode* expression=Negated();
    return PowerPrime(expression);
}
ExpressionNode* Parser::Factors()
{
    if(currenttoken->type == Id)
            return Variable();
    else if(currenttoken->type == OpenParenthesis){
            ConsumeToken();
            ExpressionNode * value = Expresion();
            if(currenttoken->type != CloseParenthesis)
                throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
            ConsumeToken();
            return value;
    }
    else if(IsLiteral(currenttoken))
    {
        return Literal();
    }
    else if(currenttoken->type == Verdadero)
    {
        ConsumeToken();
        return new ConstantBooleanNode(true);
    }
    else if(currenttoken->type == Falso)
    {
        ConsumeToken();
        return new ConstantBooleanNode(false);
    }

}


vector<StatementNode*> Parser::SiInstructionPrime()
{
    if(currenttoken->type == Fin)
    {
        ConsumeToken();
        if(currenttoken->type != Si)
            throw invalid_argument("Se esperaba palabra reservada si.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<StatementNode*> list;
        return list;
    }
    else if(currenttoken->type == Sino)
    {
        ConsumeToken();
        vector<StatementNode*> instList=InstructionList();
        if(currenttoken->type != Fin)
            throw invalid_argument("Se esperaba palabra reservada fin.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != Si)
            throw invalid_argument("Se esperaba palabra reservada si.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return instList;
    }
}

vector<CasoLineNode*> Parser:: CasoList()
{
        CasoLineNode* caseline=CasoLine();
        vector<CasoLineNode*> cases=CasoListPrime();
        cases.insert(cases.begin(),caseline);
        return cases;
}
CasoLineNode* Parser::CasoLine()
{
    vector<ExpressionNode*> conditions=LiteralList();
    if(currenttoken->type != Colon)
        throw invalid_argument("Se esperaba :.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ConsumeToken();
    vector<StatementNode*> code=InstructionList();
    return new CasoLineNode(conditions,code);
}

vector<ExpressionNode*> Parser::LiteralList()
{
    ExpressionNode * value=Literal();
    vector<ExpressionNode*> list=LiteralListPrime();
    list.insert(list.begin(),value);
    return list;
}

ExpressionNode* Parser::Literal()
{
    if(currenttoken->type == EnteroNumber)
    {
        int value=atoi(currenttoken->lexeme.c_str());
        ConsumeToken();
        return new ConstantIntegerNode(value);
    }
    else if(currenttoken->type == RealNumber)
    {
        double value=atof(currenttoken->lexeme.c_str());
        ConsumeToken();
        return new ConstantFloatNode (value);
    }
    else if(currenttoken->type == Substraction)
    {
        ConsumeToken();
        if(!IsLiteralNumber(currenttoken))
            throw invalid_argument("Se esperaba un numero entero o real.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        if(currenttoken->type == EnteroNumber)
        {
            int value=atoi(currenttoken->lexeme.c_str())*-1;
            ConsumeToken();
            return new ConstantIntegerNode(value);
        }
        else if(currenttoken->type == RealNumber)
        {
            double value=atof(currenttoken->lexeme.c_str())*-1;
            ConsumeToken();
            return new ConstantFloatNode (value);
        }
    }
    else if(currenttoken->type == Character)
    {
        char value = currenttoken->lexeme[0];
        ConsumeToken();
        return new ConstantCharacterNode(value);
    }
    else if(currenttoken->type == Str)
    {
        string value = currenttoken->lexeme;
        ConsumeToken();
        return new ConstantStringNode(value);
    }
}



vector<ExpressionNode*> Parser::LiteralListPrime()
{
    if(currenttoken->type==Coma)
    {
        ConsumeToken();
        ExpressionNode * value=Literal();
        vector<ExpressionNode*> list=LiteralListPrime();
        list.insert(list.begin(),value);
        return list;
    }
    else
    {
        vector<ExpressionNode*>list;
        return list;
    }
}

vector<CasoLineNode*> Parser::CasoListPrime()
{
    if(IsLiteral(currenttoken))
    {
        return CasoList();
    }
    else
    {
        vector<CasoLineNode*> cases;
        return cases;
    }
}

vector<StatementNode*> Parser:: CasoSino()
{
    if(currenttoken->type == Sino){
            ConsumeToken();
            if(currenttoken->type != Colon)
                throw invalid_argument("Se esperaba :.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
            ConsumeToken();
            return InstructionList();
        }
    else{
        vector<StatementNode*> list;
        return list;
    }
}

string Parser::Archive()
{
    if(currenttoken->type == Str)
    {
        string toReturn= currenttoken->lexeme;
        ConsumeToken();
        return toReturn;
    }
    else
    {
        throw invalid_argument("Se necesita String del archivo.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    }
}

vector<ModeNode*> Parser::ModeList()
{
    if(currenttoken->type == Para)
    {
        ConsumeToken();
        ModeNode* mode=Mode();
        vector<ModeNode*> list=ModeListPrime();
        if(currenttoken->type == Coma)
            throw invalid_argument("Solo pueden haber dos modos de abrir un archivo lectura o escritura.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        list.push_back(mode);
        return list;
    }
    else
    {
        vector<ModeNode*> list;
        return list;
    }
}
ModeNode* Parser::Mode()
{
    if(currenttoken->type == Escritura)
    {
        string mode=currenttoken->lexeme;
        ConsumeToken();
        return new ModeNode(mode);
    }
    else if(currenttoken->type == Lectura)
    {
        string mode=currenttoken->lexeme;
        ConsumeToken();
        return new ModeNode(mode);
    }
    else
    {
        throw invalid_argument("Ese modo de abrir archivo no existe.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));

    }
}
vector<ModeNode*> Parser::ModeListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        ModeNode* mode =Mode();
        vector<ModeNode*> list;
        list.push_back(mode);
        return list;
    }
    else
    {
        vector<ModeNode*> list;
        return list;
    }
}

vector<ExpressionNode*> Parser::Parameters()
{
    if(currenttoken->type == OpenParenthesis)
    {
        ConsumeToken();
        vector<ExpressionNode*> parameters=ExpresionListNull();
        if(currenttoken->type != CloseParenthesis)
            throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return parameters;
    }
    else
    {
        vector<ExpressionNode*> parameters;
        return parameters;
    }
}
vector<ExpressionNode*> Parser::ExpresionListNull()
{
    if(currenttoken->type != CloseParenthesis)
    {
        ExpressionNode* expression=Expresion();
        vector<ExpressionNode*> list=ExpresionListNotNullPrime();
        list.insert(list.begin(),expression);
        return list;
    }
    else{
        vector<ExpressionNode*> list;
        return list;
    }
}

vector<ExpressionNode*> Parser::ExpressionListNotNull()
{
    if(currenttoken->type == CloseBracket)
        throw invalid_argument("Se esperaban dimensiones.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    ExpressionNode* expression=Expresion();
    vector<ExpressionNode*> list=ExpresionListNotNullPrime();
    list.insert(list.begin(),expression);
    return list;
}
vector<ExpressionNode*> Parser::ExpresionListNotNullPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        ExpressionNode* expression=Expresion();
        vector<ExpressionNode*> list=ExpresionListNotNullPrime();
        list.insert(list.begin(),expression);
        return list;
    }
    else
    {
        vector<ExpressionNode*> list;
        return list;
    }
}

VariableNode *Parser::Variable()
{
    if(currenttoken->type != Id)
        throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    string id = currenttoken->lexeme;
    ConsumeToken();
    vector<AccesorNode*> list = VariablePrime();
    return new VariableNode(id,list);
}



vector<AccesorNode*> Parser::VariablePrime()
{
    if(currenttoken->type == OpenParenthesis)
    {
        ConsumeToken();
        vector<ExpressionNode*> parameters=ExpresionListNull();
        if(currenttoken->type != CloseParenthesis)
            throw invalid_argument("Se esperaba ).  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<AccesorNode*> list;
        list.push_back(new FunctionAccesorNode(parameters));
        return list;
    }
    else
    {
        return AccesorList();
    }
}

vector<AccesorNode*> Parser::AccesorList()
{
    if(currenttoken->type == Period)
    {
        ConsumeToken();
        if(currenttoken->type != Id)
            throw invalid_argument("Se esperaba id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id=currenttoken->lexeme;
        ConsumeToken();
        vector<AccesorNode*>list=AccesorList();
        list.insert(list.begin(),new FieldAccesorNode(id) );
        return list;
    }
    else if(currenttoken->type == OpenBracket)
    {
        ConsumeToken();
        vector <ExpressionNode*> indexes=ExpressionListNotNull();
        if(currenttoken->type != CloseBracket)
            throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<AccesorNode*> list=AccesorList();
        list.insert(list.begin(),new IndexAccesorNode(indexes));
        return list;
    }
    else
    {
        vector<AccesorNode*> list;
        return list;
    }
}


vector<StatementNode*> Parser::VariableDeclarations()
{
    if(currenttoken->type == DECLARAR){
        ConsumeToken();
        DeclararNode* variable=DeclarationLine();
        vector<StatementNode*> list=VariableDeclarations();
        list.insert(list.begin(),variable);
        return list;
    }
    else
    {
        vector<StatementNode*> list;
        return list;
    }
}
DeclararNode* Parser::DeclarationLine()
{
    TypeNode * type = Type();
    vector<string> idlist=IdList();
    return new DeclararNode(type,idlist);
}

vector<string> Parser::IdList()
{
    if(currenttoken->type != Id)
        throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    string id = currenttoken->lexeme;
    ConsumeToken();
    vector<string> idlist=IdListPrime();
    idlist.insert(idlist.begin(),id);
    return idlist;
}
vector<string> Parser::IdListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        if(currenttoken->type!=Id)
            throw invalid_argument("Se esperaba un id.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        string id = currenttoken->lexeme;
        ConsumeToken();
        vector<string> idlist=IdListPrime();
        idlist.insert(idlist.begin(),id);
        return idlist;
    }
    else
    {
        vector<string> list;
        return list;
    }
}

TypeNode* Parser::Type()
{
    if(currenttoken->type == Arreglo)
    {
        ConsumeToken();
        if(currenttoken->type != OpenBracket)
            throw invalid_argument("Se esperaba [.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        vector<int> dimensions=IntList();
        if(currenttoken->type != CloseBracket)
            throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != De)
            throw invalid_argument("Se esperaba palabra reservada de.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        TypeNode*type=Type();
        return new ArregloNode(dimensions,type);
    }

    else if(currenttoken->type == Entero){
        ConsumeToken();
        return new EnteroNode();
    }

    else if(currenttoken->type == Real){
        ConsumeToken();
        return new RealNode();
    }
    else if(currenttoken->type == Booleano){
        ConsumeToken();
        return new BooleanoNode();
    }
    else if(currenttoken->type == Caracter){
        ConsumeToken();
        return new CaracterNode();
    }
    else if(currenttoken->type == Archivo)
    {
        ConsumeToken();
        if (currenttoken->type != Secuencial)
            throw invalid_argument("Se esperaba palabra reservada secuencial.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new ArchivoNode();

    }
    else if(currenttoken->type == Cadena)
    {
        ConsumeToken();
        if(currenttoken->type != OpenBracket)
            throw invalid_argument("Se esperaba [.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        if(currenttoken->type != EnteroNumber )
            throw invalid_argument("Se esperaba numero entero.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        int size = atoi(currenttoken->lexeme.c_str());
        ConsumeToken();
        if(currenttoken->type != CloseBracket)
            throw invalid_argument("Se esperaba ].  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        ConsumeToken();
        return new CadenaNode(size);
    }
}
vector<int> Parser::IntList()
{
    if(currenttoken->type != EnteroNumber)
        throw invalid_argument("Se esperaba numero entero.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
    int dimension = atoi(currenttoken->lexeme.c_str());
    ConsumeToken();
    vector<int> dimensions=IntListPrime();
    dimensions.insert(dimensions.begin(),dimension);
    return dimensions;
}
vector<int> Parser::IntListPrime()
{
    if(currenttoken->type == Coma)
    {
        ConsumeToken();
        if(currenttoken->type != EnteroNumber)
            throw invalid_argument("Se esperaba numero entero.  Row:"+to_string(currenttoken->row)+"Column:"+to_string(currenttoken->column));
        int dimension = atoi(currenttoken->lexeme.c_str());
        ConsumeToken();
        vector<int> dimensions;
        dimensions.insert(dimensions.begin(),dimension);
        return dimensions;
    }
    else
    {
        vector<int> dimensions;
        return dimensions;
    }
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



