#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include <iostream>
#include <string>
#include <stdexcept>
#include "typenode.h"
#include "interpretvalue.h"
#include <string>
#include <iostream>
#include "statementnode.h"
using namespace std;

class SymbolTable
{
public:
    SymbolTable();

    TypeNode* GetVariableType(string name);
    void DeclareVariable(string name, TypeNode* value);
    StatementNode * GetFuncionRegisterType(string name);
    void DeclareFuncionRegister(string name,StatementNode* value);
    InterpretValue* GetVariableValue(string name);
    void SetVariableValue(string name, InterpretValue * value);
    static SymbolTable *Instance();
    ~SymbolTable();

private:
    static SymbolTable* instance;
    map<string,TypeNode*> variables;
    map<string,StatementNode*>registrofunciones;
    map<string,InterpretValue*>values;
};

#endif // SYMBOLTABLE_H
