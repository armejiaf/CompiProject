#ifndef GREATERTHANNODE_H
#define GREATERTHANNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
#include "valuecadena.h"
#include "valuecaracter.h"
#include "valueentero.h"
#include "valuereal.h"



class GreaterThanNode: public BinaryOperationNode
{
public:
    GreaterThanNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~GreaterThanNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // GREATERTHANNODE_H
