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
        infile.open ("test.txt");
        while (getline(infile,stringfromfile))
        {
            stringlpp+=stringfromfile+"\n";
        }
        infile.close();
        Lexer *lex=new Lexer(stringlpp);
        Parser *parser = new Parser(lex);
        vector<StatementNode*> statements=parser->Parse();
        for(unsigned int i=0;i<statements.size();i++)
            statements[i]->ValidateSemantic();
        for(unsigned int i=0;i<statements.size();i++)
            statements[i]->Interpret();
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
