#ifndef CONSTANTCHARACTERNODE_H
#define CONSTANTCHARACTERNODE_H
#include "literalnode.h"

class ConstantCharacterNode:public LiteralNode
{
public:
    char value;
    ConstantCharacterNode();
    ~ConstantCharacterNode();

    // LiteralNode interface
    string ToXml();
};

#endif // CONSTANTCHARACTERNODE_H
