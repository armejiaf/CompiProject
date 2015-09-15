#include "repitanode.h"

RepitaNode::RepitaNode(vector<StatementNode *> code, ExpressionNode *condition)
{
    this->code=code;
    this->condition=condition;
}

RepitaNode::~RepitaNode()
{

}

string RepitaNode::ToXml()
{

}

string RepitaNode::GetName()
{

}

