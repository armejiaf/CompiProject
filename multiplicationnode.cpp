#include "multiplicationnode.h"

MultiplicationNode::MultiplicationNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
    Rules["TypeRealxTypeReal"]= new RealNode();
    Rules["TypeEnteroxTypeReal"]= new RealNode();
    Rules["TypeRealxTypeEntero"]= new RealNode();
}

MultiplicationNode::~MultiplicationNode()
{

}

string MultiplicationNode::GetName()
{
    return "MultiplicationNode";
}

