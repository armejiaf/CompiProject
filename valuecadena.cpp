#include "valuecadena.h"

ValueCadena::ValueCadena(string value)
{
    this->value=value;
}

ValueCadena::~ValueCadena()
{

}

string ValueCadena::printValue()
{
    return value;
}

string ValueCadena::GetName()
{
    return "ValueCadena";
}

