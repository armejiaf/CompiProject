#include "mientrasnode.h"

MientrasNode::MientrasNode(ExpressionNode *condition,vector <StatementNode*> code)
{
    this->condition = condition;
    this->code=code;
}

MientrasNode::~MientrasNode()
{

}


string MientrasNode::GetName()
{
    return "MientrasNode";
}

void MientrasNode::ValidateSemantic()
{

    TypeNode* conditionType=condition->ValidateSemantic();
    if (conditionType->GetName().compare("TypeBoolean")!=0)
        throw invalid_argument("Se esperaba sentencia booleana en la sentencia Mientras. Columna: "+to_string(column)+" Fila: "+to_string(row) );

    for (unsigned int i=0;i<code.size();i++)
        code[i]->ValidateSemantic();

}

