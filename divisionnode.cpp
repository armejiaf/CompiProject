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

InterpretValue *DivisionNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueEntero((int)(leftVal->value / rightVal->value));
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueReal(leftVal->value / rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueReal(leftVal->value / rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueReal(leftVal->value / rightVal->value);
    }
    return 0;
}

