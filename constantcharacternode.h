#ifndef CONSTANTCHARACTERNODE_H
#define CONSTANTCHARACTERNODE_H
#include "expressionnode.h"

class ConstantCharacterNode:public ExpressionNode
{
public:
    char value;
    ConstantCharacterNode(char value);
    ~ConstantCharacterNode();

    string ToXml();
    string GetName();
};

#endif // CONSTANTCHARACTERNODE_H
