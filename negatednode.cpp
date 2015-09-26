#include "negatednode.h"

NegatedNode::NegatedNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeBoolean"]= new BooleanoNode();
}

NegatedNode::~NegatedNode()
{

}


string NegatedNode::GetName()
{
    return "NegatedNode";
}

