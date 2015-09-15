#include "sinode.h"

SiNode::SiNode(ExpressionNode *condicion, vector<StatementNode *> trueCode, vector<StatementNode *> falseCode)
{
    this->condicion=condicion;
    this->trueCode=trueCode;
    this->falseCode=falseCode;
}

SiNode::~SiNode()
{

}

string SiNode::ToXml()
{

}

string SiNode::GetName()
{

}

