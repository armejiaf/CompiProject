#include "equalnode.h"

EqualNode::EqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new BooleanoNode();
    Rules["TypeCadenaxTypeCadena"]= new BooleanoNode();
    Rules["TypeCaracterxTypeCaracter"]= new BooleanoNode();
    Rules["TypeRealxTypeReal"]= new BooleanoNode();
    Rules["TypeEnteroxTypeReal"]= new BooleanoNode();
    Rules["TypeRealxTypeEntero"]= new BooleanoNode();
}

EqualNode::~EqualNode()
{

}


string EqualNode::GetName()
{
    return "EqualNode";
}

