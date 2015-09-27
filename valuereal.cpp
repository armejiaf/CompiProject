#include "valuereal.h"

ValueReal::ValueReal(double value)
{
    this->value=value;
}

ValueReal::~ValueReal()
{

}

string ValueReal::printValue()
{
    ostringstream strs;
    strs<<value;
    string s = strs.str();
    return s;
}

string ValueReal::GetName()
{
    return string("ValueReal");
}

