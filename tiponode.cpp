#include "tiponode.h"

TipoNode::TipoNode(string id, TypeNode *type)
{
    this->id=id;
    this->type=type;
}

TipoNode::~TipoNode()
{

}


string TipoNode::GetName()
{
    return "TipoNode";
}

void TipoNode::ValidateSemantic()
{

    if (type->GetName().compare("TypeArchivo")!=0)
        throw ("Se esperaba que el tipo fuera de tipo archivo. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    SymbolTable::Instance()->DeclareVariable(id,type);

}

