#ifndef VALUECADENA_H
#define VALUECADENA_H
#include "interpretvalue.h"

class ValueCadena:public InterpretValue
{
public:
    string value;
    ValueCadena(string value);
    ~ValueCadena();

    string printValue();
    string GetName();
};

#endif // VALUECADENA_H
