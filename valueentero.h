#ifndef VALUEENTERO_H
#define VALUEENTERO_H
#include "interpretvalue.h"

class ValueEntero:public InterpretValue
{
public:
    int value;
    ValueEntero(int value);
    ~ValueEntero();

    string printValue();
    string GetName();
};

#endif // VALUEENTERO_H
