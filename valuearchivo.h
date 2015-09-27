#ifndef VALUEARCHIVO_H
#define VALUEARCHIVO_H
#include "interpretvalue.h"

class ValueArchivo:public InterpretValue
{
public:
    ValueArchivo();
    ~ValueArchivo();

    string printValue();
    string GetName();
};

#endif // VALUEARCHIVO_H
