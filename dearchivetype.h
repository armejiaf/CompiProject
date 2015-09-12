#ifndef DEARCHIVETYPE_H
#define DEARCHIVETYPE_H
#include "archivotypenode.h"
#include "expressionnode.h"

class DeArchiveType:public ArchivoTypeNode
{
public:
    ExpressionNode * type;
    DeArchiveType();
    ~DeArchiveType();

    // ArchivoTypeNode interface
    string ToXml();
};

#endif // DEARCHIVETYPE_H
