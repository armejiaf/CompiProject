#include "registronode.h"

RegistroNode::RegistroNode(VariableNode *id, vector<DeclararNode *> variables)
{
    this->id=id;
    this->variables=variables;
}

RegistroNode::~RegistroNode()
{

}

string RegistroNode::ToXml()
{

}

string RegistroNode::GetName()
{

}

