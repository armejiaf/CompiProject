#ifndef ARCHIVONODE_H
#define ARCHIVONODE_H
#include "typenode.h"
#include "valuearchivo.h"

class ArchivoNode:public TypeNode
{
public:

    ArchivoNode();
    ~ArchivoNode();

    string GetName();
    InterpretValue *GetDefaultValue();
};

#endif // ARCHIVONODE_H
