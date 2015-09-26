#include "typearchivonode.h"

ArchivoNode::ArchivoNode()
{
}

ArchivoNode::~ArchivoNode()
{

}

string ArchivoNode::GetName()
{
    return "TypeArchivo";
}

InterpretValue *ArchivoNode::GetDefaultValue()
{
    return new ValueArchivo();
}

