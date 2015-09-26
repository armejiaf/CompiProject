#include "accesorfieldnode.h"

FieldAccesorNode::FieldAccesorNode(string fieldName)
{
    this->fieldName=fieldName;
}

FieldAccesorNode::~FieldAccesorNode()
{

}



string FieldAccesorNode::GetName()
{
    return "AccesorFieldNode";
}

TypeNode *FieldAccesorNode::ValidateSemantic()
{
    return 0;
}

