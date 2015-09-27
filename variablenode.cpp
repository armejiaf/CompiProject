#include "variablenode.h"

VariableNode::VariableNode(string name, vector<AccesorNode *> accesorList)
{
    this->name=name;
    this->accesorList=accesorList;
}

VariableNode::~VariableNode()
{

}

string VariableNode::GetName()
{
    return "IdNode";
}

void VariableNode::SetValue(InterpretValue *value)
{
    SymbolTable::Instance()->SetVariableValue(name,value);
}

TypeNode *VariableNode::ValidateSemantic()
{
    if(!accesorList.empty())
        for(unsigned int i=0; i< accesorList.size();i++)
        {
            if(accesorList[i]->GetName().compare("FunctionAccesorNode")==0)
            {
                StatementNode* func=SymbolTable::Instance()->GetFuncionRegisterType(name);
                FuncionNode* funcion = dynamic_cast<FuncionNode*>(func);
                FunctionAccesorNode* llamadaFuncion = dynamic_cast<FunctionAccesorNode*>(accesorList[i]);

                if(!funcion->parameters.empty()){
                    if(llamadaFuncion->parameters.empty())
                        throw invalid_argument("Se esperaban parametros en la llamada a funcion. Columa: "+to_string(column)+" Fila: "+to_string(row));
                    if(funcion->parameters.size()!=llamadaFuncion->parameters.size())
                        throw invalid_argument("Funcion con esa cantidad de parametros no existe. Columa: "+to_string(column)+" Fila: "+to_string(row));
                    TypeNode* fun;
                    TypeNode* llamadafun;
                    for(unsigned int i=0;i< funcion->parameters.size();i++)
                    {
                        fun = funcion->parameters[i]->ValidateSemantic();
                        llamadafun = llamadaFuncion->parameters[i]->ValidateSemantic();
                        if(fun->GetName().compare(llamadafun->GetName())!=0)
                            throw invalid_argument("Tipo incompatible en los parametros de llamada funcion. Columa: "+to_string(column)+" Fila: "+to_string(row));

                    }
                }
            }
        }

    else
        return SymbolTable::Instance()->GetVariableType(name);
}

InterpretValue *VariableNode::Evaluate()
{
    return SymbolTable::Instance()->GetVariableValue(name);
}

