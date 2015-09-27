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

InterpretValue *NotEqualNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);

        return new ValueBooleano(leftVal->value != rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueBooleano(leftVal->value != rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueBooleano(leftVal->value != rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueBooleano(leftVal->value != rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueCadena")==0 && rightValue->GetName().compare("ValueCadena")==0)
    {
        ValueCadena* leftVal = dynamic_cast<ValueCadena*>(leftValue);
        ValueCadena* rightVal= dynamic_cast<ValueCadena*>(rightValue);
        return new ValueBooleano(leftVal->value != rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueBoolean")==0 && rightValue->GetName().compare("ValueBoolean")==0)
    {
        ValueBooleano* leftVal = dynamic_cast<ValueBooleano*>(leftValue);
        ValueBooleano* rightVal= dynamic_cast<ValueBooleano*>(rightValue);
        return new ValueBooleano(leftVal->value != rightVal->value);
    }
    return 0;
}
