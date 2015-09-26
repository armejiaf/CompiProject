#include "typerealnode.h"

RealNode::RealNode()
{

}

RealNode::~RealNode()
{

}

string RealNode::GetName()
{
    return "TypeReal";
}

InterpretValue *RealNode::GetDefaultValue()
{
    return new ValueReal(0.0);

}

