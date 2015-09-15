#ifndef ARREGLONODE_H
#define ARREGLONODE_H
#include "typenode.h"
#include "expressionnode.h"
#include <vector>

class ArregloNode:public TypeNode
{
public:
    vector<int> dimensions;
    TypeNode * type;

    ArregloNode(vector<int> dimensions,TypeNode * type);
    ~ArregloNode();

    string ToXml();
    string GetName();
};

#endif // ARREGLONODE_H
