#ifndef INDEXACCESORNODE_H
#define INDEXACCESORNODE_H
#include <string.h>
#include <iostream>
#include <vector>
#include "accesornode.h"
#include "expressionnode.h"
using namespace std;

class IndexAccesorNode:public AccesorNode
{
public:
    vector <ExpressionNode*> indexes;
    IndexAccesorNode(vector <ExpressionNode*> indexes);
    ~IndexAccesorNode();
    vector<AccesorNode*> accesorList;
    string GetName();

};

#endif // INDEXACCESORNODE_H
