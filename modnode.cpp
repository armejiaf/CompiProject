#include "modnode.h"

ModNode::ModNode(ExpressionNode *leftNode, ExpressionNode *rightNode):BinaryOperationNode(leftNode,rightNode)
{
    Rules["TypeEnteroxTypeEntero"]= new EnteroNode();
}

ModNode::~ModNode()
{

}


string ModNode::GetName()
{
    return "ModNode";
}

InterpretValue *ModNode::Evaluate()
{
    InterpretValue* leftValue = LeftNode->Evaluate();
    InterpretValue* rightValue = RightNode->Evaluate();
    if (leftValue->GetName().compare("ValueEntero")==0 && rightValue->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* leftVal = dynamic_cast<ValueEntero*>(leftValue);
        ValueEntero* rightVal= dynamic_cast<ValueEntero*>(rightValue);
        return new ValueEntero((int)(leftVal->value % rightVal->value));
    }
    return 0;
}

