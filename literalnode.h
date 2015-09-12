#ifndef LITERALNODE_H
#define LITERALNODE_H
#include <string.h>
#include <iostream>
#include "expressionnode.h"
using namespace std;

class LiteralNode:public ExpressionNode
{
public:
    LiteralNode();
    ~LiteralNode();
};

#endif // LITERALNODE_H
