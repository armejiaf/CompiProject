#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include <sstream>

class Parser
{
public:
    Parser(Lexer *lexer);
    Lexer *lexer;
    Token *currenttoken;
    void ConsumeToken();
    void Parse();
    ~Parser();

private:
    void Archive();
    void Programa();
    void ProgramaLpp();
    void TypesDefinition();
    void TypeDefinitionPrime();
    void TypeDefinition();
    void DeclarationLine();
    void Type();
    void InstructionList();
    void Instruction();
    void FunctionDeclarations();
    void VariableDeclarations();
    void VariableDeclarationsPrime();
    void IntListPrime();
    void RegisterDeclarations();
    void FunctionDeclaration();
    void FunctionHeader();
    void FunctionArguments();
    void ParameterList();
    void ParameterDeclaration();
    void ParameterListPrime();
    void RegisterDeclaration();
    void IdList();
    void IdListPrime();
    void IntList();
    void ArchiveType();
    bool IsInstruccion(Token *token);
    string to_string(int tostring );
    void SiInstruction();
    void ParaInstruction();
    void ValueAllocInstruction();
    void EscribaInstruction();
    void MientrasInstruction();
    void RepitaInstruction();
    void CasoInstruction();
    void AbrirArchiveInstruction();
    void CerrarArchiveInstruction();
    void LeerArchiveInstruction();
    void EscribirArchiveInstruction();
    void LlamarInstruction();
    void RetorneInstruction();
    void Expresion();
    void SiInstructionPrime();
    void Variable();
    void IdVariable();
    void VariablePrime();
    void CasoList();
    void CasoSino();
    void CasoLine();
    void CasoListPrime();
    void Parameters();
    void IdVariablePrime();
    bool IsLiteral(Token *token);
    void Literal();
    void LiteralList();
    void LiteralListPrime();
    void ModeList();
    void ModeListPrime();
    void Mode();
    bool IsLiteralNumber(Token *token);
    void SubExpresion();
    void ExpresionInequalitiesPrime();
    void Term();
    void SubExpresionPrime();
    void TermPrime();
    void Negated();
    void ExpresionInequalities();
    void ConditionalExpresion();
    void NegatedPrime();
    void Power();
    void PowerPrime();
    void Factors();
    bool IsType(Token *token);
    void AccesorList();
    void ExpressionListNotNull();
    void ExpresionListNotNullPrime();
    void ExpresionListNull();
};

#endif // PARSER_H
