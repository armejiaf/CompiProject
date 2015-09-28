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

string CasoNode::GetName()
{
    return "SwitchNode";
}

void CasoNode::ValidateSemantic()
{
    TypeNode* caseType = idCase->ValidateSemantic();
    if(caseType->GetName().compare("TypeCadena")==0
       || caseType->GetName().compare("TypeArchivo")==0
       ||caseType->GetName().compare("TypeBoolean")==0
       ||caseType->GetName().compare("TypeArreglo")==0)
        throw invalid_argument("El tipo del caso tiene que ser id entero, real, o caracter. Columna: "+to_string(column)+" Fila: "+to_string(row));

    if(cases.empty())
        throw invalid_argument("Se esperaba almenos un caso. Columna: "+to_string(column)+" Fila: "+to_string(row));
    TypeNode*caseLineType;
    for(unsigned int i=0;i<cases.size();i++)
    {
        for(unsigned int j=0;j<cases[i]->conditions.size();j++)
        {
            caseLineType =cases[i]->conditions[j]->ValidateSemantic();
            if(caseType->GetName().compare(caseLineType->GetName())!=0)
                throw invalid_argument("Tipo de dato incompatible en caso. Columna: "+to_string(column)+" Fila: "+to_string(row));
        }
        if(!cases[i]->code.empty())
            for(unsigned int k=0;k<cases[i]->code.size();k++)
                cases[i]->code[k]->ValidateSemantic();
        if(!defaultNode.empty())
            for(unsigned int z=0;z<defaultNode.size();z++)
                defaultNode[i]->ValidateSemantic();
    }
}

void CasoNode::Interpret()
{
    InterpretValue * conditionType= idCase->Evaluate();
    if(conditionType->GetName().compare("ValueEntero")==0)
    {
        ValueEntero* condition = dynamic_cast<ValueEntero*>(conditionType);

        for(unsigned int i=0;i<cases.size();i++)
        {
            for(unsigned int j=0;j<cases[i]->conditions.size();j++)
            {
                ValueEntero* caso=dynamic_cast<ValueEntero*>(cases[i]->conditions[j]->Evaluate());
                if(caso->value == condition->value)
                    for(unsigned int k=0;k<cases[i]->code.size();k++)
                       cases[i]->code[k]->Interpret();
                else if(!defaultNode.empty())
                    for(unsigned int z=0;z<defaultNode.size();z++)
                        defaultNode[i]->Interpret();
            }
        }
    }
     else if(conditionType->GetName().compare("ValueReal")==0)
    {
        ValueReal* condition = dynamic_cast<ValueReal*>(conditionType);

        for(unsigned int i=0;i<cases.size();i++)
        {
            for(unsigned int j=0;j<cases[i]->conditions.size();j++)
            {
                ValueReal* caso=dynamic_cast<ValueReal*>(cases[i]->conditions[j]->Evaluate());
                if(caso->value == condition->value)
                    for(unsigned int k=0;k<cases[i]->code.size();k++)
                       cases[i]->code[k]->Interpret();
                else if(!defaultNode.empty())
                    for(unsigned int z=0;z<defaultNode.size();z++)
                        defaultNode[i]->Interpret();
            }
        }
    }
    else if(conditionType->GetName().compare("ValueCaracter")==0){
        ValueCaracter* condition = dynamic_cast<ValueCaracter*>(conditionType);

        for(unsigned int i=0;i<cases.size();i++)
        {
            for(unsigned int j=0;j<cases[i]->conditions.size();j++)
            {
                ValueCaracter* caso=dynamic_cast<ValueCaracter*>(cases[i]->conditions[j]->Evaluate());
                if(caso->value == condition->value)
                    for(unsigned int k=0;k<cases[i]->code.size();k++)
                       cases[i]->code[k]->Interpret();
                else if(!defaultNode.empty())
                    for(unsigned int z=0;z<defaultNode.size();z++)
                        defaultNode[i]->Interpret();
            }
        }
    }
}

