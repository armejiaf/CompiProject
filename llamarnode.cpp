#include "llamarnode.h"

LlamarNode::LlamarNode(VariableNode *idProcedure, vector<ExpressionNode *> parameters)
{
    this->idProcedure=idProcedure;
    this->parameters=parameters;
}

LlamarNode::~LlamarNode()
{

}

string LlamarNode::ToXml()
{

}

string LlamarNode::GetName()
{

}

