#include "funcionnode.h"

FuncionNode::FuncionNode(string id, TypeNode *returnType, vector<ParameterNode *> parameters, vector<StatementNode *> variables, vector<StatementNode *> code)
{
    this->id=id;
    this->type=returnType;
    this->variables=variables;
    this->parameters=parameters;
    this->code=code;
}

FuncionNode::~FuncionNode()
{

}

string FuncionNode::GetName()
{
    return "FuncionNode";
}

void FuncionNode::ValidateSemantic()
{
    if(!variables.empty())
        for (unsigned int i=0;i<variables.size();i++)
            variables[i]->ValidateSemantic();
    bool retorneExists=false;
    if(!code.empty())
        for(unsigned int i=0;i<code.size();i++)
            if(code[i]->GetName().compare("RetorneNode")==0)
                retorneExists=true;
        if(!retorneExists)
            throw invalid_argument("La funcion no tiene valor de retorno. Columna: "+to_string(column)+" Fila: "+to_string(row) );
        for (unsigned int i=0;i<code.size();i++){
            if(code[i]->GetName().compare("RetorneNode")==0)
            {
                RetorneNode* r = dynamic_cast<RetorneNode*>(code[i]);
                TypeNode* returnVariable=r->returnVariable->ValidateSemantic();
                if(returnVariable->GetName().compare(type->GetName())!=0)
                    throw invalid_argument("El tipo de retorno no es el mismo tipo de la funcion. Columna: "+to_string(column)+" Fila: "+to_string(row) );
            }
            code[i]->ValidateSemantic();
        }
    SymbolTable::Instance()->DeclareFuncionRegister(id,this);
}

