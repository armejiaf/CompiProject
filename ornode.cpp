#include "ornode.h"

OrNode::OrNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeBooleanxTypeBoolean"]= new BooleanoNode();
}

OrNode::~OrNode()
{

}


string OrNode::GetName()
{
    return "OrNode";
}

