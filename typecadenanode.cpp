#include "typecadenanode.h"

CadenaNode::CadenaNode(int size)
{
    this->size=size;
}

CadenaNode::~CadenaNode()
{

}

string CadenaNode::GetName()
{
    return "TypeCadena";
}

InterpretValue *CadenaNode::GetDefaultValue()
{
    return new ValueCadena("");
}

