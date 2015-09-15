#include "abrirarchivonode.h"

AbrirArchivoNode::AbrirArchivoNode(VariableNode *archiveToOpen, VariableNode *id, vector<ModeNode *> modes)
{
    this->archiveToOpen=archiveToOpen;
    this->id=id;
    this->modes=modes;
}

AbrirArchivoNode::~AbrirArchivoNode()
{

}

string AbrirArchivoNode::ToXml()
{

}

string AbrirArchivoNode::GetName()
{

}

