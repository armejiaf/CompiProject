#include "accesorfunctionnode.h"

FunctionAccesorNode::FunctionAccesorNode(vector<ExpressionNode *> parameters)
{
    this->parameters=parameters;
}

FunctionAccesorNode::~FunctionAccesorNode()
{

}

string FunctionAccesorNode::GetName()
{
    return "FunctionAccesorNode";
}

