#include "negatednode.h"

NegatedNode::NegatedNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeBoolean"]= new BooleanoNode();
}

NegatedNode::~NegatedNode()
{

}


string NegatedNode::GetName()
{
    return "NegatedNode";
}

InterpretValue *NegatedNode::Evaluate()
{
    InterpretValue* rightValue = RightNode->Evaluate();
    if (rightValue->GetName().compare("ValueBoolean")==0)
    {
        ValueBooleano* rightVal= dynamic_cast<ValueBooleano*>(rightValue);

        return new ValueBooleano(!(rightVal->value));
    }
}

