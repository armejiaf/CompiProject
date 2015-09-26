#ifndef LEXER_H
#define LEXER_H
#include "token.h"
#include <exception>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdexcept>
#include <ctype.h>
#include <string.h>
#include <map>
#include <sstream>


using namespace std;

class Lexer
{
public:
    string to_string(int tostring);
    Lexer(string input);
    char GetCurrentSymbol();
    char GetNextSymbol();
    Token *GetToken();
    map<string, const char*> operators;
    map<string, const char*> reservedwords;
private:
    string input;
    unsigned int position;
    int column;
    int row;
    int state;
    ~Lexer();
};

#endif // LEXER_H
