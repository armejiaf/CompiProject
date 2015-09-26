#ifndef VALUEREAL_H
#define VALUEREAL_H
#include "interpretvalue.h"

class ValueReal:public InterpretValue
{
public:
    double value;
    ValueReal(double value);
    ~ValueReal();
    string printValue();
};

#endif // VALUEREAL_H
