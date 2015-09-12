#ifndef CONSTANTSTRINGNODE_H
#define CONSTANTSTRINGNODE_H
#include "literalnode.h"

class ConstantStringNode:public LiteralNode
{
public:
    string value;
    ConstantStringNode();
    ~ConstantStringNode();

    // LiteralNode interface
    string ToXml();
};

#endif // CONSTANTSTRINGNODE_H
