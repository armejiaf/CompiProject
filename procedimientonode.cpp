#include "procedimientonode.h"

ProcedimientoNode::ProcedimientoNode(string id, vector<ParameterNode *> parameters, vector<StatementNode *> variables, vector<StatementNode *> code)
{
    this->id=id;
    this->parameters=parameters;
    this->variables=variables;
    this->code=code;
}

ProcedimientoNode::~ProcedimientoNode()
{

}



string ProcedimientoNode::GetName()
{
    return "ProcedimientoNode";
}

void ProcedimientoNode::ValidateSemantic()
{
    if(!variables.empty())
        for (unsigned int i=0;i<variables.size();i++)
            variables[i]->ValidateSemantic();
    if(!code.empty())
        for (unsigned int i=0;i<code.size();i++)
            code[i]->ValidateSemantic();

    SymbolTable::Instance()->DeclareFuncionRegister(id,this);
}

