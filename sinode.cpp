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


string SiNode::GetName()
{
    return "SiNode";
}

void SiNode::ValidateSemantic()
{
   /* TypeNode * condicionType = condicion->ValidateSemantic();
    if (condicionType->GetName().compare("TypeBoolean")!=0)
        throw ("Se esperaba expresion booleana en la sentencia Si. Columna: "+to_string(column)+" Fila: "+to_string(row) );
    if(!trueCode.empty())
        for (unsigned int i=0;i<trueCode.size();i++)
        {
            trueCode[i]->ValidateSemantic();
        }

    if (!falseCode.empty())
        for (unsigned int i=0;i<falseCode.size();i++)
        {
            falseCode[i]->ValidateSemantic();
        }*/

}

void SiNode::Interpret()
{
    ValueBooleano* conditionVal= dynamic_cast<ValueBooleano*>(condicion->Evaluate());
    if(conditionVal->value)
        for (unsigned int i=0;i<trueCode.size();i++)
             trueCode[i]->Interpret();

    else
        for (unsigned int i=0;i<falseCode.size();i++)
             falseCode[i]->Interpret();

}

