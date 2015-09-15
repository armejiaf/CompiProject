#include "casonode.h"

CasoNode::CasoNode(VariableNode *idCase, vector<CasoLineNode *> cases, vector<StatementNode *> defaultNode)
{
    this->idCase=idCase;
    this->cases=cases;
    this->defaultNode=defaultNode;
}

CasoNode::~CasoNode()
{

}

string CasoNode::ToXml()
{

}

string CasoNode::GetName()
{

}

