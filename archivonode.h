#ifndef ARCHIVONODE_H
#define ARCHIVONODE_H
#include "expressionnode.h"

class ArchivoNode:public ExpressionNode
{
public:

    ArchivoNode();
    ~ArchivoNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // ARCHIVONODE_H
