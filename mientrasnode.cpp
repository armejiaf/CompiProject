#include "mientrasnode.h"

MientrasNode::MientrasNode(ExpressionNode *condition,vector <StatementNode*> code)
{
    this->condition = condition;
    this->code=code;
}

MientrasNode::~MientrasNode()
{

}

string MientrasNode::ToXml()
{

}

string MientrasNode::GetName()
{

}

