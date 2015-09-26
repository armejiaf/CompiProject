#include "typearreglonode.h"

ArregloNode::ArregloNode(vector<int> dimensions, TypeNode *type)
{
    this->dimensions=dimensions;
    this->type=type;
}

ArregloNode::~ArregloNode()
{

}


string ArregloNode::GetName()
{
    return "TypeArreglo";
}

InterpretValue *ArregloNode::GetDefaultValue()
{
    return new ValueArreglo();
}

