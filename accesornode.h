#ifndef ACCESORNODE_H
#define ACCESORNODE_H
#include <string.h>
#include <iostream>

using namespace std;

class AccesorNode
{
public:
    virtual string ToXml()=0;
    virtual string GetName()=0;
    int row;
    int column;
    AccesorNode();
    ~AccesorNode();
};

#endif // ACCESORNODE_H
