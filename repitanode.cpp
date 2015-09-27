#include "repitanode.h"

RepitaNode::RepitaNode(vector<StatementNode *> code, ExpressionNode *condition)
{
    this->code=code;
    this->condition=condition;
}

RepitaNode::~RepitaNode()
{

}

string RepitaNode::GetName()
{
    return "RepitaNode";
}

void RepitaNode::ValidateSemantic()
{
    TypeNode* conditionType = condition->ValidateSemantic();
    if (conditionType->GetName().compare("TypeBoolean")!=0)
        throw invalid_argument("Se esperaba expression booleana en la sentencia Repita. Columna: "+to_string(column)+" Fila: "+to_string(row) );

    for (unsigned int i=0;i<code.size();i++)
        code[i]->ValidateSemantic();

}

void RepitaNode::Interpret()
{
    ValueBooleano* conditionVal = dynamic_cast<ValueBooleano*>(condition->Evaluate());
    do{

        for (unsigned int i=0;i<code.size();i++)
        {
            code[i]->Interpret();
        }
        conditionVal = dynamic_cast<ValueBooleano*>(condition->Evaluate());
    }while(conditionVal->value);
}

