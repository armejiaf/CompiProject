#ifndef GREATEREQUALNODE_H
#define GREATEREQUALNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
#include "valuebooleano.h"
#include "valuecadena.h"
#include "valuecaracter.h"
#include "valueentero.h"
#include "valuereal.h"
class GreaterEqualNode:public BinaryOperationNode
{
public:
    GreaterEqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterEqualNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // GREATEREQUALNODE_H
