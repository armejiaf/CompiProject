#include "modenode.h"

ModeNode::ModeNode(string modeType)
{
    this->modeType=modeType;
}

ModeNode::~ModeNode()
{

}


string ModeNode::GetName()
{
    return "ModeNode";
}

