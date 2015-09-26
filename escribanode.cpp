#include "escribanode.h"

EscribaNode::EscribaNode(vector<ExpressionNode *> printVariables)
{
    this->printVariables = printVariables;
}

EscribaNode::~EscribaNode()
{

}

string EscribaNode::GetName()
{
    return "EscribaNode";
}

void EscribaNode::ValidateSemantic()
{
    if(printVariables.empty())
        throw invalid_argument("No se especificaron expresiones a imprimir. Columna: "+to_string(column)+" Fila: "+to_string(row) );

    for(unsigned int i=0;i<printVariables.size();i++)
    {
        TypeNode* type =printVariables[i]->ValidateSemantic();
        if(type->GetName().compare("TypeArchivo")==0 || type->GetName().compare("TypeArreglo")==0)
            throw invalid_argument("Tipo incompatible para imprimir. Columna: "+to_string(column)+" Fila: "+to_string(row) );

    }
}

