#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include <string.h>
#include <iostream>
#include <vector>
#include "accesornode.h"
#include "expressionnode.h"
using namespace std;

class VariableNode:public ExpressionNode
{
public:
    string name;
    vector <AccesorNode*> accesorList;
    VariableNode(string name,vector <AccesorNode*> accesorList);
    ~VariableNode();

    string ToXml();
    string GetName();
};

#endif // VARIABLENODE_H
