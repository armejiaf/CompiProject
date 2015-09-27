#include "valuecaracter.h"

ValueCaracter::ValueCaracter(char value)
{
    this->value=value;
}

ValueCaracter::~ValueCaracter()
{

}

string ValueCaracter::printValue()
{
    string s;
    s+=value;
    return s;
}

string ValueCaracter::GetName()
{
    return string("ValueCaracter");
}

