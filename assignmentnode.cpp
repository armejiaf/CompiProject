#include "assignmentnode.h"

AssignmentNode::AssignmentNode(VariableNode *id, ExpressionNode *value)
{
    this->value=value;
    this->id=id;
}

AssignmentNode::~AssignmentNode()
{

}

string AssignmentNode::ToXml()
{

}

string AssignmentNode::GetName()
{

}

