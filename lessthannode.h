#ifndef LESSTHANNODE_H
#define LESSTHANNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
#include "valueentero.h"
#include "valuereal.h"
#include "valuecadena.h"

class LessThanNode:public BinaryOperationNode
{
public:
    LessThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessThanNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // LESSTHANNODE_H
