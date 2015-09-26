#include "typebooleanonode.h"

BooleanoNode::BooleanoNode()
{

}

BooleanoNode::~BooleanoNode()
{

}


string BooleanoNode::GetName()
{
    return "TypeBoolean";
}

InterpretValue *BooleanoNode::GetDefaultValue()
{
    return new ValueBooleano(false);
}

