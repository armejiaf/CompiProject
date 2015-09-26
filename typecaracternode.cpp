#include "typecaracternode.h"

CaracterNode::CaracterNode()
{

}

CaracterNode::~CaracterNode()
{

}

string CaracterNode::GetName()
{
    return "TypeCaracter";
}

InterpretValue *CaracterNode::GetDefaultValue()
{
    return new ValueCaracter(' ');
}

