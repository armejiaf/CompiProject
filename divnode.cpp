#include "divnode.h"

DivNode::DivNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
}

DivNode::~DivNode()
{

}

string DivNode::GetName()
{
    return "DivNode";
}

