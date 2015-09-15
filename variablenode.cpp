#include "variablenode.h"

VariableNode::VariableNode(string name, vector<AccesorNode *> accesorList)
{
    this->name=name;
    this->accesorList=accesorList;
}

VariableNode::~VariableNode()
{

}

string VariableNode::ToXml()
{

}

string VariableNode::GetName()
{

}

