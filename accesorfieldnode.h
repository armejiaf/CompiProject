#ifndef FIELDACCESORNODE_H
#define FIELDACCESORNODE_H
#include <string.h>
#include <iostream>
#include "accesornode.h"
#include <vector>
using namespace std;
class FieldAccesorNode: public AccesorNode
{
public:
    string fieldName;
    FieldAccesorNode(string fieldName);
    ~FieldAccesorNode();
    vector<AccesorNode*> accesorlist;
    string GetName();
    TypeNode *ValidateSemantic();
};

#endif // FIELDACCESORNODE_H
