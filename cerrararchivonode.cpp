#include "cerrararchivonode.h"

CerrarArchivoNode::CerrarArchivoNode(VariableNode *archiveToClose)
{
    this->archiveToClose=archiveToClose;
}

CerrarArchivoNode::~CerrarArchivoNode()
{

}


string CerrarArchivoNode::GetName()
{
    return "CerrarArchivoNode";
}

void CerrarArchivoNode::ValidateSemantic()
{
    TypeNode* type = archiveToClose->ValidateSemantic();
    if (type->GetName().compare("TypeArchivo")!=0)
        throw invalid_argument("Se esperaba que variable fuera de tipo archivo. Columna: "+to_string(column)+" Fila: "+to_string(row) );

}

void CerrarArchivoNode::Interpret()
{

}

