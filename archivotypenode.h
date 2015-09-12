#ifndef ARCHIVOTYPENODE_H
#define ARCHIVOTYPENODE_H
#include <string.h>
#include <iostream>
using namespace std;

class ArchivoTypeNode
{
public:
    int column;
    int row;
    virtual string ToXml()=0;
    ArchivoTypeNode();
    ~ArchivoTypeNode();
};

#endif // ARCHIVOTYPENODE_H
