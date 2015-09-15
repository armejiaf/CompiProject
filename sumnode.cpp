#include "sumnode.h"

SumNode::SumNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{

}

SumNode::~SumNode()
{

}

string SumNode::ToXml()
{
    return "<SumNode>"+LeftNode->ToXml()+RightNode->ToXml()+"</SumNode>";
}

string SumNode::GetName()
{

}

