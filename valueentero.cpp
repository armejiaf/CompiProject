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
    char *intStr = itoa(value,intStr,10);
    string str = string(intStr);
    return str;
}

