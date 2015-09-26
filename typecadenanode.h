#ifndef CADENANODE_H
#define CADENANODE_H
#include "typenode.h"
#include "valuecadena.h"

class CadenaNode:public TypeNode
{
public:
    int size;
    CadenaNode(int size);
    ~CadenaNode();

    string GetName();

    InterpretValue *GetDefaultValue();
};

#endif // CADENANODE_H
