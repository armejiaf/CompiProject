#ifndef NOTEQUAL_H
#define NOTEQUAL_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
#include "valuecadena.h"
#include "valueentero.h"
#include "valuereal.h"
class NotEqualNode:public BinaryOperationNode
{
public:
    NotEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~NotEqualNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // NOTEQUAL_H
