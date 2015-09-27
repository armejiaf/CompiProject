#include "divnode.h"

DivNode::DivNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
}

DivNode::~DivNode()
{

}

string DivNode::GetName()
{
    return "DivNode";
}

InterpretValue *DivNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueEntero((int)(leftVal->value / rightVal->value));
    }
    return 0;
}

