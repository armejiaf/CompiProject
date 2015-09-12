#ifndef ARREGLONODE_H
#define ARREGLONODE_H
#include "expressionnode.h"
#include <vector>
class ArregloNode:public ExpressionNode
{
public:
    vector<ExpressionNode*> dimensions;
    ExpressionNode * type;

    ArregloNode();
    ~ArregloNode();

    // ExpressionNode interface
    string ToXml();
};

#endif // ARREGLONODE_H
