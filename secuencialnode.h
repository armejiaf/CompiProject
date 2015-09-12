#ifndef SECUENCIALNODE_H
#define SECUENCIALNODE_H
#include "archivotypenode.h"

class SecuencialNode:public ArchivoTypeNode
{
public:
    SecuencialNode();
    ~SecuencialNode();

    // ArchivoTypeNode interface
    string ToXml();
};

#endif // SECUENCIALNODE_H
