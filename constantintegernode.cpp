#include "constantintegernode.h"

ConstantIntegerNode::ConstantIntegerNode(int value)
{
    this->value=value;
}

ConstantIntegerNode::~ConstantIntegerNode()
{

}

string ConstantIntegerNode::GetName()
{
    return "ConstantIntegerNode";
}

TypeNode *ConstantIntegerNode::ValidateSemantic()
{
    return new EnteroNode();
}

