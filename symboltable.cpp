#include "symboltable.h"

SymbolTable* SymbolTable::instance=0;

SymbolTable::SymbolTable()
{

}

TypeNode *SymbolTable::GetVariableType(string name)
{
    if(variables.find(name) == variables.end() )
        throw invalid_argument("Variable "+ name +" no existe.");
    return variables.at(name);
}

void SymbolTable::DeclareVariable(string name, TypeNode *value)
{
    if(variables.find(name)!=variables.end())
        throw invalid_argument("Variable "+ name +" ya existe.");
    variables[name]=value;
    values[name]=value->GetDefaultValue();
}

StatementNode *SymbolTable::GetFuncionRegisterType(string name)
{
    if(variables.find(name)!=variables.end())
        throw invalid_argument(name +" no existe.");
    return registrofunciones[name];
}

void SymbolTable::DeclareFuncionRegister(string name, StatementNode *value)
{
    if(registrofunciones.find(name)!=registrofunciones.end())
        throw invalid_argument("Funcion, procedimiento o registro "+ name +" ya existe.");
    registrofunciones[name]=value;

}

InterpretValue *SymbolTable::GetVariableValue(string name)
{
    return values[name];
}

void SymbolTable::SetVariableValue(string name, InterpretValue *value)
{
    values[name]=value;
}

SymbolTable *SymbolTable::Instance()
{
    if(instance==0)
       instance=new SymbolTable();
    return instance;
}


SymbolTable::~SymbolTable()
{

}



