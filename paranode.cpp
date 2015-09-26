#include "paranode.h"

ParaNode::ParaNode(AssignmentNode *counter, ExpressionNode *condition, vector<StatementNode *> code)
{
    this->counter=counter;
    this->condition=condition;
    this->code=code;
}

ParaNode::~ParaNode()
{

}


string ParaNode::GetName()
{
    return "ParaNode";
}

void ParaNode::ValidateSemantic()
{
    counter->ValidateSemantic();
    TypeNode* type = counter->value->ValidateSemantic();
    if (type->GetName().compare("TypeEntero")!=0)
        throw invalid_argument("Se esperaba variable entero en la sentencia Para. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    type=condition->ValidateSemantic();
    if (type->GetName().compare("TypeEntero")!=0)
        throw invalid_argument("Se esperaba variable entero en la sentencia Para. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    for (unsigned int i=0;i<code.size();i++)
        code[i]->ValidateSemantic();
}

