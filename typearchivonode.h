#ifndef ARCHIVONODE_H
#define ARCHIVONODE_H
#include "typenode.h"

class ArchivoNode:public TypeNode
{
public:
    TypeNode * type;

    ArchivoNode(TypeNode * type);
    ~ArchivoNode();

    string ToXml();
    string GetName();
};

#endif // ARCHIVONODE_H
