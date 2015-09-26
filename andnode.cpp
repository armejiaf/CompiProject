#include "andnode.h"

AndNode::AndNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeBooleanxTypeBoolean"]= new BooleanoNode();
}

AndNode::~AndNode()
{

}

string AndNode::GetName()
{
    return "AndNode";
}
