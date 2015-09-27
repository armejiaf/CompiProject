#ifndef CONSTANTCHARACTERNODE_H
#define CONSTANTCHARACTERNODE_H
#include "expressionnode.h"
#include "typecaracternode.h"

class ConstantCharacterNode:public ExpressionNode
{
public:
    char value;
    ConstantCharacterNode(char value);
    ~ConstantCharacterNode();

    string GetName();
    TypeNode *ValidateSemantic();
    InterpretValue *Evaluate();
};

#endif // CONSTANTCHARACTERNODE_H
