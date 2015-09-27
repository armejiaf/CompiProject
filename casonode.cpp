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
    if(cases.empty())
        throw invalid_argument("Se esperaba almenos un caso. Columna: "+to_string(column)+" Fila: "+to_string(row));
    TypeNode*caseLineType;
    for(unsigned int i=0;i<cases.size();i++)
    {
        for(unsigned int j=0;j<cases[i]->conditions.size();j++)
        {
            caseLineType =cases[i]->conditions[j]->ValidateSemantic();
            if(caseType->GetName().compare(caseLineType->GetName())!=0)
                throw invalid_argument("Dato incompatible en caso. Columna: "+to_string(column)+" Fila: "+to_string(row));
        }
        if(!cases[i]->code.empty())
            for(unsigned int k=0;k<cases[i]->code.size();k++)
                cases[i]->code[k]->ValidateSemantic();
    }
}

void CasoNode::Interpret()
{
    ValueEntero* condition = dynamic_cast<ValueEntero*>(idCase->Evaluate());

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

