#include "typeenteronode.h"

EnteroNode::EnteroNode()
{

}

EnteroNode::~EnteroNode()
{

}



string EnteroNode::GetName()
{
    return "TypeEntero";
}

InterpretValue *EnteroNode::GetDefaultValue()
{
    return new ValueEntero(0);
}

