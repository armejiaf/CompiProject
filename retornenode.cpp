#include "retornenode.h"

RetorneNode::RetorneNode(ExpressionNode *returnVariable)
{
    this->returnVariable=returnVariable;
}

RetorneNode::~RetorneNode()
{

}

string RetorneNode::GetName()
{
    return "RetorneNode";
}

void RetorneNode::ValidateSemantic()
{
    return;
}

void RetorneNode::Interpret()
{

}

