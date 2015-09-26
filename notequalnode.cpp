#include "notequalnode.h"

NotEqualNode::NotEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new BooleanoNode();
    Rules["TypeCadenaxTypeCadena"]= new BooleanoNode();
    Rules["TypeRealxTypeReal"]= new BooleanoNode();
    Rules["TypeEnteroxTypeReal"]= new BooleanoNode();
    Rules["TypeRealxTypeEntero"]= new BooleanoNode();
    Rules["TypeCaracterxTypeCaracter"]= new BooleanoNode();

}

NotEqualNode::~NotEqualNode()
{

}

string NotEqualNode::GetName()
{
    return "NotEqualNode";
}
