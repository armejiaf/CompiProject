#include "divisionnode.h"

DivisionNode::DivisionNode(ExpressionNode * leftNode, ExpressionNode* rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
    Rules["TypeRealxTypeReal"]= new RealNode();
    Rules["TypeEnteroxTypeReal"]= new RealNode();
    Rules["TypeRealxTypeEntero"]= new RealNode();
}

DivisionNode::~DivisionNode()
{

}



string DivisionNode::GetName()
{
    return "DivisionNode";
}

