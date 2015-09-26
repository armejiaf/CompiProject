#include "substractionnode.h"

SubstractionNode::SubstractionNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
    Rules["TypeRealxTypeReal"]= new RealNode();
    Rules["TypeEnteroxTypeReal"]= new RealNode();
    Rules["TypeRealxTypeEntero"]= new RealNode();
}

SubstractionNode::~SubstractionNode()
{

}


string SubstractionNode::GetName()
{
    return "SubstractionNode";
}

