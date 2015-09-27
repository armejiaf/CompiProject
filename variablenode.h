#ifndef VARIABLENODE_H
#define VARIABLENODE_H
#include <string.h>
#include <iostream>
#include <vector>
#include "accesornode.h"
#include "expressionnode.h"
#include "accesorfieldnode.h"
#include "accesorfunctionnode.h"
#include "accesorindexnode.h"
#include "funcionnode.h"
#include "interpretvalue.h"
using namespace std;

class VariableNode:public ExpressionNode
{
public:
    string name;
    vector <AccesorNode*> accesorList;
    VariableNode(string name,vector <AccesorNode*> accesorList);
    ~VariableNode();

    string GetName();
    void SetValue(InterpretValue *value);
    TypeNode *ValidateSemantic();
    InterpretValue *Evaluate();
};

#endif // VARIABLENODE_H
