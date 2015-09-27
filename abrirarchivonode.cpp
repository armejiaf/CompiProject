#include "abrirarchivonode.h"

AbrirArchivoNode::AbrirArchivoNode(string archiveName, VariableNode *archiveType, vector<ModeNode *> modes)
{
    this->archiveName=archiveName;
    this->archiveType=archiveType;
    this->modes=modes;
}

AbrirArchivoNode::~AbrirArchivoNode()
{

}

string AbrirArchivoNode::GetName()
{
    return "AbrirArchivoNode";
}

void AbrirArchivoNode::ValidateSemantic()
{
    TypeNode* archiveT=archiveType->ValidateSemantic();
    if(archiveT->GetName().compare("TypeArchivo")!=0)
        throw invalid_argument("Se esperaba que la variable fuese de tipo archivo. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    if(modes.size() >2 || modes.size() < 1)
        throw invalid_argument("Hay muchos o muy pocos modos para el archivo. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    bool lectura=false;
    bool escritura=false;
    for(unsigned int i=0;i<modes.size();i++)
    {
        if(modes[i]->modeType.compare("lectura")==0)
        {
            if(!lectura)
            {
                lectura=true;
                continue;
            }
            else
                throw invalid_argument("Solo se esperaba un modo de lectura. Columna: "+to_string(column)+" Fila: "+to_string(row) );

        }
        else if(modes[i]->modeType.compare("escritura")==0)
        {
            if(!escritura)
            {
                escritura=true;
                continue;
            }
            else
                throw invalid_argument("Solo se esperaba un modo de escritura. Columna: "+to_string(column)+" Fila: "+to_string(row) );

        }
        else
            throw invalid_argument("Ese modo de archivo no existe. Columna: "+to_string(column)+" Fila: "+to_string(row) );

    }
}

void AbrirArchivoNode::Interpret()
{

}

