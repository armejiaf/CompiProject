#ifndef SECUENCIALNODE_H
#define SECUENCIALNODE_H
#include "typenode.h"

class SecuencialNode:public TypeNode
{
public:
    SecuencialNode();
    ~SecuencialNode();

    string ToXml();
    string GetName();
};

#endif // SECUENCIALNODE_H
