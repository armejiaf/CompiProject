#ifndef MODENODE_H
#define MODENODE_H
#include <string.h>
#include <iostream>
using namespace std;


class ModeNode
{
public:
    int row;
    int column;
    string modeType;
    ModeNode();
    ~ModeNode();
};

#endif // MODENODE_H
