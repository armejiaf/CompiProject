#include "procedimientonode.h"

ProcedimientoNode::ProcedimientoNode(VariableNode *id, vector<ParameterNode *> parameters, vector<StatementNode *> code)
{
    this->id=id;
    this->parameters=parameters;
    this->code=code;
}

ProcedimientoNode::~ProcedimientoNode()
{

}

string ProcedimientoNode::ToXml()
{

}

string ProcedimientoNode::GetName()
{

}

