#include "declararnode.h"

DeclararNode::DeclararNode(TypeNode *type, vector<string> idList)
{
    this->type=type;
    this->idList=idList;
}

DeclararNode::~DeclararNode()
{

}



string DeclararNode::GetName()
{
    return "DeclararNode";
}

void DeclararNode::ValidateSemantic()
{
    for(unsigned int i =0;i<idList.size();i++)
        SymbolTable::Instance()->DeclareVariable(idList[i],type);
}

