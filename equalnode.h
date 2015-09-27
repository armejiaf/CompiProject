#ifndef EQUALNODE_H
#define EQUALNODE_H
#include "binaryoperationnode.h"
#include "typebooleanonode.h"
#include "valuecadena.h"
#include "valuecaracter.h"
#include "valueentero.h"
#include "valuereal.h"
#include "valuebooleano.h"


class EqualNode: public BinaryOperationNode
{
public:
    EqualNode(ExpressionNode *leftNode, ExpressionNode *rightNode);
    ~EqualNode();

    string GetName();
    InterpretValue *Evaluate();
};

#endif // EQUALNODE_H
