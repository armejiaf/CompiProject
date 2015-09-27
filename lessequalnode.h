#ifndef LESSEQUALNODE_H
#define LESSEQUALNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
#include "valuecadena.h"
#include "valuecaracter.h"
#include "valueentero.h"
#include "valuereal.h"
class LessEqualNode:public BinaryOperationNode
{
public:
    LessEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~LessEqualNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // LESSEQUALNODE_H
