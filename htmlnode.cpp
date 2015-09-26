#include "htmlnode.h"

HTMLNode::HTMLNode(string html)
{
    this->html=html;
}

HTMLNode::~HTMLNode()
{

}

string HTMLNode::GetName()
{
    return "HTMLNode";
}

void HTMLNode::ValidateSemantic()
{
}

