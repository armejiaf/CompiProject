#include "paranode.h"

ParaNode::ParaNode(AssignmentNode *counter, ExpressionNode *condition, vector<StatementNode *> code)
{
    this->counter=counter;
    this->condition=condition;
    this->code=code;
}

ParaNode::~ParaNode()
{

}

string ParaNode::ToXml()
{


}

string ParaNode::GetName()
{

}

