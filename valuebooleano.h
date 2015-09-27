#ifndef VALUEBOOLEANO_H
#define VALUEBOOLEANO_H
#include "interpretvalue.h"

class ValueBooleano:public InterpretValue
{
public:
    bool value;
    ValueBooleano(bool value);
    ~ValueBooleano();
    string printValue();
    string GetName();
};

#endif // VALUEBOOLEANO_H
