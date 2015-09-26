#include "modnode.h"

ModNode::ModNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
}

ModNode::~ModNode()
{

}


string ModNode::GetName()
{
    return "ModNode";
}

