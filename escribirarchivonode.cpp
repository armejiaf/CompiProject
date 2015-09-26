#include "escribirarchivonode.h"

EscribirArchivoNode::EscribirArchivoNode(VariableNode *archive, VariableNode *data)
{
    this->archive=archive;
    this->data=data;
}

EscribirArchivoNode::~EscribirArchivoNode()
{

}

string EscribirArchivoNode::GetName()
{
    return "EscribirArchivoNode";
}

void EscribirArchivoNode::ValidateSemantic()
{
    TypeNode* archiveType= archive->ValidateSemantic();
    if(archiveType->GetName().compare("TypeArchivo")!=0)
        throw invalid_argument("Se esperaba tipo archivo en la primer variable. Columna: "+to_string(column)+" Fila: "+to_string(row) );

}

