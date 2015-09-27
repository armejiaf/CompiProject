#include "powernode.h"

PowerNode::PowerNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
    Rules["TypeRealxTypeReal"]= new RealNode();
    Rules["TypeEnteroxTypeReal"]= new RealNode();
    Rules["TypeRealxTypeEntero"]= new RealNode();
}

PowerNode::~PowerNode()
{

}

string PowerNode::GetName()
{
    return "PowerNode";
}

InterpretValue *PowerNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueEntero((int)(pow((double)leftVal->value, (double)rightVal->value)));
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueReal(pow(leftVal->value, rightVal->value));
    }
    else if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueReal(pow((double)leftVal->value, rightVal->value));
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueReal(pow(leftVal->value, (double)rightVal->value));
    }
    return 0;
}

