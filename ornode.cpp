#include "ornode.h"

OrNode::OrNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeBooleanxTypeBoolean"]= new BooleanoNode();
}

OrNode::~OrNode()
{

}


string OrNode::GetName()
{
    return "OrNode";
}

InterpretValue *OrNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueBoolean")==0 && rightValue->GetName().compare("ValueBoolean")==0)
    {
        ValueBooleano* leftVal = dynamic_cast<ValueBooleano*>(leftValue);
        ValueBooleano* rightVal= dynamic_cast<ValueBooleano*>(rightValue);
        return new ValueBooleano(leftVal->value || rightVal->value);
    }
    return 0;
}

