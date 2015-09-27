#ifndef CONSTANTSTRINGNODE_H
#define CONSTANTSTRINGNODE_H
#include "expressionnode.h"
#include "typecadenanode.h"
class ConstantStringNode:public ExpressionNode
{
public:
    string value;
    ConstantStringNode(string value);
    ~ConstantStringNode();

    string GetName();
    TypeNode *ValidateSemantic();
    InterpretValue *Evaluate();
};

#endif // CONSTANTSTRINGNODE_H
