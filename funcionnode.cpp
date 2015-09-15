#include "funcionnode.h"

FuncionNode::FuncionNode(VariableNode *id, TypeNode *type, vector<ParameterNode *> parameters, vector<StatementNode *> code)
{
    this->id=id;
    this->type=type;
    this->parameters=parameters;
    this->code=code;
}

FuncionNode::~FuncionNode()
{

}

string FuncionNode::ToXml()
{

}

string FuncionNode::GetName()
{

}

