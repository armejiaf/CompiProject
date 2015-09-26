#include "binaryoperationnode.h"

BinaryOperationNode::BinaryOperationNode(ExpressionNode *leftNode, ExpressionNode *rightNode)
{
    LeftNode=leftNode;
    RightNode=rightNode;
}

BinaryOperationNode::~BinaryOperationNode()
{

}

TypeNode *BinaryOperationNode::ValidateSemantic()
{
    TypeNode* leftType=0;
    if(LeftNode!=0)
        leftType = LeftNode->ValidateSemantic();
    TypeNode* rightType = RightNode->ValidateSemantic();

    string pair="";
    if(leftType!=0)
        pair = leftType->GetName()+"x"+rightType->GetName();
    else
        pair=rightType->GetName();
    if(Rules.find(pair) != Rules.end())
    {
        return Rules[pair];
    }
    else
    {
        throw invalid_argument("Tipo "+this->GetName()+" es incompatible con pair "+ pair);
    }
}

