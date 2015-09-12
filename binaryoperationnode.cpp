#include "binaryoperationnode.h"

BinaryOperationNode::BinaryOperationNode(ExpressionNode *leftNode, ExpressionNode *rightNode)
{
    LeftNode=leftNode;
    RightNode=rightNode;
}

BinaryOperationNode::~BinaryOperationNode()
{

}

