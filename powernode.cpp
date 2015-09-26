#include "powernode.h"

PowerNode::PowerNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
    Rules["TypeRealxTypeReal"]= new RealNode();
    Rules["TypeEnteroxTypeReal"]= new RealNode();
    Rules["TypeRealxTypeEntero"]= new RealNode();
}

PowerNode::~PowerNode()
{

}

string PowerNode::GetName()
{
    return "PowerNode";
}

