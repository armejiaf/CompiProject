#ifndef PARENTNODE_H
#define PARENTNODE_H
#include <string.h>
#include <iostream>
#include <sstream>

using namespace std;

class ParentNode
{
public:

    virtual string GetName()=0;
    string to_string(int tostring);

    int row;
    int column;
    ParentNode();
    ~ParentNode();
};

#endif // PARENTNODE_H
