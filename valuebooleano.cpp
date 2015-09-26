#include "valuebooleano.h"

ValueBooleano::ValueBooleano(bool value)
{
    this->value=value;
}

ValueBooleano::~ValueBooleano()
{

}

string ValueBooleano::printValue()
{
    return value ? "true" : "false";
}



