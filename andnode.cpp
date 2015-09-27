#include "andnode.h"

AndNode::AndNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeBooleanxTypeBoolean"]= new BooleanoNode();
}

AndNode::~AndNode()
{

}

string AndNode::GetName()
{
    return "AndNode";
}

InterpretValue *AndNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueBoolean")==0 && rightValue->GetName().compare("ValueBoolean")==0)
    {
        ValueBooleano* leftVal = dynamic_cast<ValueBooleano*>(leftValue);
        ValueBooleano* rightVal= dynamic_cast<ValueBooleano*>(rightValue);
        return new ValueBooleano(leftVal->value && rightVal->value);
    }
    return 0;
}
