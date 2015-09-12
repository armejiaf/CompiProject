#ifndef INDEXACCESORNODE_H
#define INDEXACCESORNODE_H
#include <string.h>
#include <iostream>
#include <vector>
#include "accesornode.h"
#include "expressionnode.h"
using namespace std;

class IndexAccesorNode:AccesorNode
{
public:
    vector <ExpressionNode*> indexes;
    IndexAccesorNode();
    ~IndexAccesorNode();

    // AccesorNode interface
    string ToXml();
};

#endif // INDEXACCESORNODE_H
