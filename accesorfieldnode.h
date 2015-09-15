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
    FieldAccesorNode(string fieldName);
    ~FieldAccesorNode();

    string ToXml();
    string GetName();
};

#endif // FIELDACCESORNODE_H
