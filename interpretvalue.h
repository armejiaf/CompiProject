#ifndef INTERPETVALUE_H
#define INTERPETVALUE_H
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

class InterpretValue
{
public:
    InterpretValue();
    ~InterpretValue();
    virtual string printValue()=0;

};

#endif // INTERPETVALUE_H
