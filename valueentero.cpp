#include "valueentero.h"

ValueEntero::ValueEntero(int value)
{
    this->value=value;
}

ValueEntero::~ValueEntero()
{

}

string ValueEntero::printValue()
{
    char *intStr = new char;
    intStr=itoa(value,intStr,10);
    string str = string(intStr);
    return str;
}

string ValueEntero::GetName()
{
    return "ValueEntero";
}

