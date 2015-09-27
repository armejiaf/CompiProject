#include "leerarchivonode.h"

LeerArchivoNode::LeerArchivoNode(VariableNode * archive,VariableNode * data)
{
    this->archive=archive;
    this->data=data;
}

LeerArchivoNode::~LeerArchivoNode()
{

}


string LeerArchivoNode::GetName()
{
    return "LeerArchivoNode";
}

void LeerArchivoNode::ValidateSemantic()
{
    TypeNode* archiveType= archive->ValidateSemantic();
    if(archiveType->GetName().compare("TypeArchivo")!=0)
        throw invalid_argument("Se esperaba tipo archivo en la primer variable. Columna: "+to_string(column)+" Fila: "+to_string(row) );
}

void LeerArchivoNode::Interpret()
{

}

