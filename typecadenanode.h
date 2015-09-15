#ifndef CADENANODE_H
#define CADENANODE_H
#include "typenode.h"

class CadenaNode:public TypeNode
{
public:
    int size;
    CadenaNode(int size);
    ~CadenaNode();

    string ToXml();
    string GetName();
};

#endif // CADENANODE_H
