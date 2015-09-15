#ifndef CONSTANTSTRINGNODE_H
#define CONSTANTSTRINGNODE_H
#include "expressionnode.h"

class ConstantStringNode:public ExpressionNode
{
public:
    string value;
    ConstantStringNode(string value);
    ~ConstantStringNode();

    string ToXml();
    string GetName();
};

#endif // CONSTANTSTRINGNODE_H
