#include "registronode.h"

RegistroNode::RegistroNode(string id, vector<StatementNode *> variables)
{
    this->id=id;
    this->variables=variables;
}

RegistroNode::~RegistroNode()
{

}


string RegistroNode::GetName()
{
    return "RegistroNode";
}

void RegistroNode::ValidateSemantic()
{
    for (unsigned int i=0;i<variables.size();i++)
        variables[i]->ValidateSemantic();
    SymbolTable::Instance()->DeclareFuncionRegister(id,this);

}

void RegistroNode::Interpret()
{

}

