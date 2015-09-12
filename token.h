#ifndef TOKEN_H
#define TOKEN_H
#include "tokentype.h"
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Token
{
public:
    Token(TokenType type,string lexeme,int column,int row);
    TokenType type;
    string lexeme;
    int column;
    int row;
    void Print();

    ~Token();


private:
    map<TokenType, string> types;
};

#endif // TOKEN_H
