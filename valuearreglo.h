#ifndef VALUEARREGLO_H
#define VALUEARREGLO_H
#include "interpretvalue.h"

class ValueArreglo: public InterpretValue
{
public:

    ValueArreglo();
    ~ValueArreglo();
    string printValue();
};

#endif // VALUEARREGLO_H
