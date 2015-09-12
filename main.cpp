#include <QCoreApplication>
#include <fstream>
#include "parser.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    try
    {
        string stringfromfile;
        string stringlpp="";
        ifstream infile;
        infile.open ("Code.txt");
        while (getline(infile,stringfromfile))
        {
            stringlpp+=stringfromfile+"\n";
        }
        infile.close();
        Lexer *lex=new Lexer(stringlpp);
        Parser *parser = new Parser(lex);
        parser->Parse();
        /*Token *currentToken = lex->GetToken();
        while(currentToken->type !=  EOFi)
        {q
            currentToken->Print();
            currentToken = lex->GetToken();
        }
        currentToken->Print();*/
    }catch (exception& e){
        cout<<e.what()<<"\n";
    }





    return 0;
}
