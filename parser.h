#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "sinode.h"
#include "powernode.h"
#include "repitanode.h"
#include "substractionnode.h"
#include "cerrararchivonode.h"
#include "sumnode.h"
#include "tiponode.h"
#include "paranode.h"
#include "ornode.h"
#include "notequalnode.h"
#include "negatednode.h"
#include "multiplicationnode.h"
#include "modnode.h"
#include "modenode.h"
#include "mientrasnode.h"
#include "llamarnode.h"
#include "lessthannode.h"
#include "lessequalnode.h"
#include "leerarchivonode.h"
#include "greaterequalnode.h"
#include "greaterthannode.h"
#include "escribirarchivonode.h"
#include "escribanode.h"
#include "equalnode.h"
#include "casonode.h"
#include "casolinenode.h"
#include "assignmentnode.h"
#include "andnode.h"
#include "accesornode.h"
#include "accesorfieldnode.h"
#include "accesorindexnode.h"
#include "abrirarchivonode.h"
#include "divnode.h"
#include "divisionnode.h"
#include "declararnode.h"
#include "parameternode.h"
#include "parameterreferencenode.h"
#include "parametersimplenode.h"
#include "expressionnode.h"
#include "htmlnode.h"
#include "funcionnode.h"
#include "procedimientonode.h"
#include "variablenode.h"
#include "constantbooleannode.h"
#include "constantcharacternode.h"
#include "constantfloatnode.h"
#include "constantintegernode.h"
#include "constantstringnode.h"
#include "typearchivonode.h"
#include "typearreglonode.h"
#include "typebooleanonode.h"
#include "typecadenanode.h"
#include "typecaracternode.h"
#include "typeenteronode.h"
#include "typerealnode.h"
#include "statementnode.h"
#include "registronode.h"
#include "declararnode.h"
#include "retornenode.h"
#include "typenode.h"
#include "accesorfunctionnode.h"
#include <algorithm>
#include <sstream>

class Parser
{
public:
    Parser(Lexer *lexer);
    Lexer *lexer;
    Token *currenttoken;
    void ConsumeToken();
    vector<StatementNode *> Parse();
    ~Parser();

private:
    string Archive();
    vector<StatementNode *> Programa();
    vector<StatementNode *> ProgramaLpp();
    DeclararNode *DeclarationLine();
    TypeNode *Type();
    vector<StatementNode *> InstructionList();
    StatementNode *Instruction();
    vector<StatementNode *> FunctionDeclarations();
    vector<StatementNode *> VariableDeclarations();
    vector<int> IntListPrime();
    vector<StatementNode *> RegisterDeclarations();
    StatementNode *FunctionDeclaration();
    vector<ParameterNode *> FunctionArguments();
    vector<ParameterNode *> ParameterList();
    ParameterNode *ParameterDeclaration();
    vector<ParameterNode *> ParameterListPrime();
    StatementNode *RegisterDeclaration();
    vector<string> IdList();
    vector<string> IdListPrime();
    vector<int> IntList();
    string to_string(int tostring );
    ExpressionNode *Expresion();
    vector<StatementNode *> SiInstructionPrime();
    VariableNode *Variable();
    vector<AccesorNode *> VariablePrime();
    vector<CasoLineNode*> CasoList();
    vector<StatementNode*> CasoSino();
    CasoLineNode *CasoLine();
    vector<CasoLineNode *> CasoListPrime();
    vector<ExpressionNode *> Parameters();
    ExpressionNode *Literal();
    vector<ExpressionNode *> LiteralList();
    vector<ExpressionNode *> LiteralListPrime();
    vector<ModeNode *> ModeList();
    vector<ModeNode *> ModeListPrime();
    ModeNode *Mode();
    ExpressionNode *SubExpresion();
    ExpressionNode *ExpresionInequalitiesPrime(ExpressionNode *param);
    ExpressionNode* Term();
    ExpressionNode *SubExpresionPrime(ExpressionNode *param);
    ExpressionNode *TermPrime(ExpressionNode *param);
    ExpressionNode *Negated();
    ExpressionNode *ExpresionInequalities();
    ExpressionNode* ConditionalExpresion(ExpressionNode *param);
    ExpressionNode *Power();
    ExpressionNode *PowerPrime(ExpressionNode *param);
    ExpressionNode *Factors();
    vector<AccesorNode *> AccesorList();
    vector<ExpressionNode*> ExpressionListNotNull();
    vector<ExpressionNode*> ExpresionListNotNullPrime();
    vector<ExpressionNode *> ExpresionListNull();
    bool IsType(Token *token);
    bool IsLiteralNumber(Token *token);
    bool IsLiteral(Token *token);
    bool IsInstruccion(Token *token);
};

#endif // PARSER_H
