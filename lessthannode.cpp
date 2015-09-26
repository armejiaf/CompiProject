#include "lessthannode.h"

LessThanNode::LessThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new BooleanoNode();
    Rules["TypeCadenaxTypeCadena"]= new BooleanoNode();
    Rules["TypeRealxTypeReal"]= new BooleanoNode();
    Rules["TypeEnteroxTypeReal"]= new BooleanoNode();
    Rules["TypeRealxTypeEntero"]= new BooleanoNode();
    Rules["TypeCaracterxTypeCaracter"]= new BooleanoNode();

}

LessThanNode::~LessThanNode()
{

}



string LessThanNode::GetName()
{
    return "LessThanNode";
}

