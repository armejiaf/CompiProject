#include "constantcharacternode.h"

ConstantCharacterNode::ConstantCharacterNode(char value)
{
    this->value=value;
}

ConstantCharacterNode::~ConstantCharacterNode()
{

}

string ConstantCharacterNode::GetName()
{
    return "ConstantCharacterNode";
}

TypeNode *ConstantCharacterNode::ValidateSemantic()
{
    return new CaracterNode();
}

