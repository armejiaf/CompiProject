#include "accesorindexnode.h"

IndexAccesorNode::IndexAccesorNode(vector<ExpressionNode*> indexes)
{
    this->indexes=indexes;
}

IndexAccesorNode::~IndexAccesorNode()
{

}


string IndexAccesorNode::GetName()
{
    return "AccesorIndexNode";
}

TypeNode *IndexAccesorNode::ValidateSemantic()
{
    return 0;
}

