#include "llamarnode.h"

LlamarNode::LlamarNode(string idProcedure, vector<ExpressionNode *> parameters)
{
    this->idProcedure=idProcedure;
    this->parameters=parameters;
}

LlamarNode::~LlamarNode()
{

}



string LlamarNode::GetName()
{
    return "LlamarNode";
}

void LlamarNode::ValidateSemantic()
{
    StatementNode* proc = SymbolTable::Instance()->GetFuncionRegisterType(idProcedure);
    if (proc->GetName().compare("ProcedimientoNode")!=0)
        throw invalid_argument("Se esperaba que la llamada fuese a un procedimiento. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    ProcedimientoNode* procedimiento = dynamic_cast<ProcedimientoNode*>(proc);

    TypeNode* typeI;
    TypeNode* typeJ;
    for(unsigned int i=0;i<parameters.size();i++)
    {
        for (unsigned int j=0;j<procedimiento->parameters.size();i++)
        {
            typeI=parameters[i]->ValidateSemantic();
            typeJ=procedimiento->parameters[j]->ValidateSemantic();
            if(typeI->GetName().compare(typeJ->GetName())!=0)
                throw invalid_argument("Tipo no compatible en parametros de procedimiento. Columna: "+to_string(column)+" Fila: "+to_string(row) );
        }
    }

}

