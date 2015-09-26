#include "greaterthannode.h"

GreaterThanNode::GreaterThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new BooleanoNode();
    Rules["TypeCadenaxTypeCadena"]= new BooleanoNode();
    Rules["TypeRealxTypeReal"]= new BooleanoNode();
    Rules["TypeEnteroxTypeReal"]= new BooleanoNode();
    Rules["TypeRealxTypeEntero"]= new BooleanoNode();
    Rules["TypeCaracterxTypeCaracter"]= new BooleanoNode();

}

GreaterThanNode::~GreaterThanNode()
{

}


string GreaterThanNode::GetName()
{
    return "GreaterThanNode";
}

