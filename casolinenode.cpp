#include "casolinenode.h"

CasoLineNode::CasoLineNode(vector<ExpressionNode *> conditions, vector<StatementNode *> code)
{
    this->conditions=conditions;
    this->code=code;
}

CasoLineNode::~CasoLineNode()
{

}


string CasoLineNode::GetName()
{
    return "CaseNode";
}

