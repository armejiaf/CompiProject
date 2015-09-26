#include "constantstringnode.h"

ConstantStringNode::ConstantStringNode(string value)
{
    this->value=value;
}

ConstantStringNode::~ConstantStringNode()
{

}

string ConstantStringNode::GetName()
{
    return "ConstantStringNode";
}

TypeNode *ConstantStringNode::ValidateSemantic()
{
    return new CadenaNode(100);
}

