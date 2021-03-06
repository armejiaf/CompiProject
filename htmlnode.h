#ifndef HTMLNODE_H
#define HTMLNODE_H
#include "statementnode.h"

class HTMLNode:public StatementNode
{
public:
    string html;
    HTMLNode(string html);
    ~HTMLNode();

    string GetName();
    void ValidateSemantic();
    void Interpret();
};

#endif // HTMLNODE_H
