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
        throw invalid_argument("Tipos incompatibles entre si. Columna: "+to_string(column)+" Fila: "+to_string(row));
    }
}

void AssignmentNode::Interpret()
{
    id->SetValue(value->Evaluate());
}
