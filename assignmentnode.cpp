#include "assignmentnode.h"

AssignmentNode::AssignmentNode(VariableNode *id, ExpressionNode *value)
{
    this->id=id;
    this->value=value;
}

AssignmentNode::~AssignmentNode()
{

}



string AssignmentNode::GetName()
{
    return "AssignmentNode";
}

void AssignmentNode::ValidateSemantic()
{

    TypeNode* variableType=id->ValidateSemantic();
    TypeNode* valueType = value->ValidateSemantic();
    if (variableType->GetName().compare(valueType->GetName())!=0)
    {
        throw invalid_argument("Tipos incompatibles entre si en asignacion. Columna: "+to_string(column)+" Fila: "+to_string(row));
    }
}

void AssignmentNode::Interpret()
{
    TypeNode* variableType= SymbolTable::Instance()->GetVariableType(id->name);
    if(variableType->GetName().compare("TypeCadena")==0)
    {
        CadenaNode* strType = dynamic_cast<CadenaNode*>(variableType);
        ValueCadena * str = dynamic_cast<ValueCadena*>(value->Evaluate());
        if(str->value.size() > strType->size)
        {
            string val=str->value.substr(0,strType->size);
            str->value=val;
            id->SetValue(str);
        }
        else
        {
           id->SetValue(value->Evaluate());
        }
    }
    else
        id->SetValue(value->Evaluate());
}
