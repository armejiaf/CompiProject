#ifndef FIELDACCESORNODE_H
#define FIELDACCESORNODE_H
#include <string.h>
#include <iostream>
#include <list>
#include "accesornode.h"
using namespace std;
class FieldAccesorNode: public AccesorNode
{
public:
    string fieldName;
    FieldAccesorNode();
    ~FieldAccesorNode();

    // AccesorNode interface
    string ToXml();
};

#endif // FIELDACCESORNODE_H
