#ifndef MODENODE_H
#define MODENODE_H
#include "parentnode.h"

class ModeNode:public ParentNode
{
public:

    string modeType;
    ModeNode(string modeType);
    ~ModeNode();

    string ToXml();
    string GetName();
};

#endif // MODENODE_H
