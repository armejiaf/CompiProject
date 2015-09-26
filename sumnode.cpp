#include "sumnode.h"

SumNode::SumNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
              Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
              Rules["TypeCadenaxTypeCadena"]= new CadenaNode(100);
              Rules["TypeRealxTypeReal"]= new RealNode();
              Rules["TypeEnteroxTypeReal"]= new RealNode();
              Rules["TypeRealxTypeEntero"]= new RealNode();
}

SumNode::~SumNode()
{

}


string SumNode::GetName()
{
    return "SumNode";
}

