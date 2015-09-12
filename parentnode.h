#ifndef PARENTNODE_H
#define PARENTNODE_H
#include <string.h>
#include <iostream>
using namespace std;

class ParentNode
{
public:
    virtual string ToXml()=0;
    virtual string GetName()=0;
    int row;
    int column;
    ParentNode();
    ~ParentNode();
};

#endif // PARENTNODE_H
