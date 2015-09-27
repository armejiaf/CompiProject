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

InterpretValue *SumNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueEntero(leftVal->value + rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueReal(leftVal->value + rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueReal")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueReal* rightVal= dynamic_cast<ValueReal*>(rightValue);
        return new ValueReal(leftVal->value + rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueReal")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueReal* leftVal = dynamic_cast<ValueReal*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueReal(leftVal->value + rightVal->value);
    }
    else if (leftValue->GetName().compare("ValueCadena")==0 && rightValue->GetName().compare("ValueCadena")==0)
    {
        ValueCadena* leftVal = dynamic_cast<ValueCadena*>(leftValue);
        ValueCadena* rightVal= dynamic_cast<ValueCadena*>(rightValue);
        string value="";
        value+=leftVal->value;
        value+=rightVal->value;
        return new ValueCadena(value);
    }
    return 0;
}

