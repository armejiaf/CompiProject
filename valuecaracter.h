#ifndef VALUECARACTER_H
#define VALUECARACTER_H
#include "interpretvalue.h"

class ValueCaracter:public InterpretValue
{
public:
    char value;
    ValueCaracter(char value);
    ~ValueCaracter();

    string printValue();
};

#endif // VALUECARACTER_H
