#include "lexer.h"

string Lexer::to_string(int tostring)
{
    ostringstream stm ;
    stm << tostring ;
    return stm.str() ;
}

Lexer::Lexer(string input)
{
    this->input=input;
    this->position = 0;
    this->column= 0;
    this->row=1;
    this->state=0;
    this->operators["+"]="+";
    this->operators["*"]="*";
    this->operators["-"]="-";
    this->operators["="]="=";
    this->operators[":"]=":";
    this->operators["("]="(";
    this->operators[")"]=")";
    this->operators["/"]="/";
    this->operators["["]="[";
    this->operators["]"]="]";
    this->operators["^"]="^";
    this->operators["."]=".";
    this->operators["\n"]="\n";
    this->operators[","]=",";

    this->reservedwords["escribir"]="escribir";
    this->reservedwords["funcion"]="funcion";
    this->reservedwords["no"]="no";
    this->reservedwords["inicio"]="inicio";
    this->reservedwords["escriba"]="escriba";
    this->reservedwords["fin"]="fin";
    this->reservedwords["llamar"]="llamar";
    this->reservedwords["entero"]="entero";
    this->reservedwords["real"]="real";
    this->reservedwords["caracter"]="caracter";
    this->reservedwords["booleano"]="booleano";
    this->reservedwords["cadena"]="cadena";
    this->reservedwords["mod"]="mod";
    this->reservedwords["div"]="div";
    this->reservedwords["y"]="y";
    this->reservedwords["o"]="o";
    this->reservedwords["si"]="si";
    this->reservedwords["sino"]="sino";
    this->reservedwords["entonces"]="entonces";
    this->reservedwords["caso"]="caso";
    this->reservedwords["mientras"]="mientras";
    this->reservedwords["haga"]="haga";
    this->reservedwords["para"]="para";
    this->reservedwords["hasta"]="hasta";
    this->reservedwords["repita"]="repita";
    this->reservedwords["procedimiento"]="procedimiento";
    this->reservedwords["var"]="var";
    this->reservedwords["lectura"]="lectura";
    this->reservedwords["escritura"]="escritura";
    this->reservedwords["archivo"]="archivo";
    this->reservedwords["secuencial"]="secuencial";
    this->reservedwords["tipo"]="tipo";
    this->reservedwords["es"]="es";
    this->reservedwords["de"]="de";
    this->reservedwords["como"]="como";
    this->reservedwords["abrir"]="abrir";
    this->reservedwords["cerrar"]="cerrar";
    this->reservedwords["leer"]="leer";
    this->reservedwords["verdadero"]="verdadero";
    this->reservedwords["falso"]="falso";
    this->reservedwords["retorne"]="retorne";
    this->reservedwords["declarar"]="declarar";
    this->reservedwords["registro"]="registro";
    this->reservedwords["arreglo"]="arreglo";

}

char Lexer::GetCurrentSymbol()
{
    if (position < input.length())
    {
        return input[position];
    }
    return '\0';
}

char Lexer::GetNextSymbol()
{
    position++;
    char symbol = GetCurrentSymbol();
    if (symbol == '\n')
    {
        row++;
        column = 0;
    }
    else
    {
        column++;
    }
    return symbol;
}

Token* Lexer::GetToken()
{
    char symbol = GetCurrentSymbol();
    string lexeme = "";
    int col = column;
    while (true)
    {
        switch (state)
        {
            case 0:
                if(symbol=='\0'){
                    return new Token(EOFi,lexeme,col,row);
                }
                if(symbol=='<'){
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state=1;
                }
                else if (isspace(symbol))
                {
                    symbol = GetNextSymbol();
                    col = column;
                }
                else{
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 2;
                }
                break;
            case 1:
                if(symbol=='%'){
                    lexeme=lexeme.substr(0, lexeme.size()-1);;
                    symbol = GetNextSymbol();
                    state=3;
                    return new Token(HTML,lexeme,col,row);
                }

                else if (symbol=='<'){
                    lexeme+=symbol;
                    symbol =GetNextSymbol();
                }
                else{
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 2;
                }
                break;
            case 2:
                if(symbol!='<'){
                    if(symbol == '\0'){
                        state=0;
                        return new Token(HTML,lexeme,col,row);
                    }
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                }
                else{
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 1;
                }
                break;
            case 3:
                if (isdigit(symbol))
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 6;
                }
                else if (symbol == '+' || symbol == '*' || symbol == '-' || symbol == '='
                    || symbol == ':' || symbol == '(' || symbol == ')' || symbol=='.'
                    || symbol == '[' || symbol == ']' || symbol=='^' || symbol==',')
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 5;
                }
                else if(symbol=='\"'){

                    symbol = GetNextSymbol();
                    state = 9;
                }
                else if(symbol == '\''){
                    lexeme +=symbol;
                    symbol =GetNextSymbol();
                    state= 20;
                }
                else if(symbol == '/'){
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state = 18;
                }
                else if(symbol=='>'){
                    lexeme +=symbol;
                    symbol=GetNextSymbol();
                    state=11;
                }
                else if(symbol =='<'){
                    lexeme+=symbol;
                    symbol=GetNextSymbol();
                    state=13;
                }
                else if(symbol =='%'){
                    symbol=GetNextSymbol();
                    state=17;
                }
                else if (isspace(symbol))
                {
                    symbol = GetNextSymbol();
                    col = column;
                }else if (isalpha(symbol) || symbol== '_')
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 4;
                }
                else
                {
                    string error="Invalid symbol ";
                    error+=symbol;
                    throw invalid_argument(error+" Columna: "+to_string(col)+" Fila: "+to_string(row));
                }
                break;

            case 4:
                if (isalpha(symbol) || isdigit(symbol)|| symbol=='_')
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                }
                else
                {
                    int i=0;
                    string lex="";
                    while (lexeme[i])
                    {
                      lex+=tolower(lexeme[i]);
                      i++;
                    }


                    if(strcmp(lex.c_str(),reservedwords["entero"])==0){
                        state=3;
                        return new Token(Entero,lexeme,col,row );
                    }
                    else if(strcmp(lex.c_str(),reservedwords["retorne"])==0){
                        state=3;
                        return new Token(Retorne,lexeme,col,row );
                    }
                    else if(strcmp(lex.c_str(),reservedwords["verdadero"])==0){
                        state=3;
                        return new Token(Verdadero,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["falso"])==0){
                        state=3;
                        return new Token(Falso,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["inicio"])==0){
                        state=3;
                        return new Token(Inicio,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["escriba"])==0){
                        state=3;
                        return new Token(Escriba,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["fin"])==0){
                        state=3;
                        return new Token(Fin,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["llamar"])==0){
                        state=3;
                        return new Token(Llamar,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["real"])==0){
                        state=3;
                        return new Token(Real,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["caracter"])==0){
                        state=3;
                        return new Token(Caracter,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["booleano"])==0){
                        state=3;
                        return new Token(Booleano,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["cadena"])==0){
                        state=3;
                        return new Token(Cadena,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["mod"])==0){
                        state=3;
                        return new Token(Mod,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["div"])==0){
                        state=3;
                        return new Token(IntegerDivision,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["y"])==0){
                        state=3;
                        return new Token(And,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["o"])==0){
                        state=3;
                        return new Token(Or,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["si"])==0){
                        state=3;
                        return new Token(Si,lexeme,col,row);
                    }else if(strcmp(lex.c_str(),reservedwords["no"])==0){
                        state=3;
                        return new Token(No,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["sino"])==0){
                        state=3;
                        return new Token(Sino,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["entonces"])==0){
                        state=3;
                        return new Token(Entonces,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["caso"])==0){
                        state=3;
                        return new Token(Caso,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["mientras"])==0){
                        state=3;
                        return new Token(Mientras,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["escribir"])==0){
                        state=3;
                        return new Token(Escribir,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["haga"])==0){
                        state=3;
                        return new Token(Haga,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["para"])==0){
                        state=3;
                        return new Token(Para,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["hasta"])==0){
                        state=3;
                        return new Token(Hasta,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["repita"])==0){
                        state=3;
                        return new Token(Repita,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["procedimiento"])==0){
                        state=3;
                        return new Token(Procedimiento,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["var"])==0){
                        state=3;
                        return new Token(ParameterVariable,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["lectura"])==0){
                        state=3;
                        return new Token(Lectura,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["escritura"])==0){
                        state=3;
                        return new Token(Escritura,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["archivo"])==0){
                        state=3;
                        return new Token(Archivo,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["secuencial"])==0){
                        state=3;
                        return new Token(Secuencial,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["tipo"])==0){
                        state=3;
                        return new Token(Tipo,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["es"])==0){
                        state=3;
                        return new Token(Es,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["de"])==0){
                        state=3;
                        return new Token(De,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["como"])==0){
                        state=3;
                        return new Token(Como,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["abrir"])==0){
                        state=3;
                        return new Token(Abrir,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["cerrar"])==0){
                        state=3;
                        return new Token(Cerrar,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["leer"])==0){
                        state=3;
                        return new Token(Leer,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["funcion"])==0){
                        state=3;
                        return new Token(Funcion,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["declarar"])==0){
                        state=3;
                        return new Token(DECLARAR,lexeme,col,row);
                    }

                    else if(strcmp(lex.c_str(),reservedwords["registro"])==0){
                        state=3;
                        return new Token(Registro,lexeme,col,row);
                    }
                    else if(strcmp(lex.c_str(),reservedwords["arreglo"])==0){
                        state=3;
                        return new Token(Arreglo,lexeme,col,row);
                    }
                    else{
                        state=3;
                        return new Token(Id,lexeme,col,row);
                    }
                }
                break;
            case 5:
                if (strcmp(lexeme.c_str(),operators["+"])==0){
                    state=3;
                    return new Token(Sum,lexeme,col,row );
                }
                else if(strcmp(lexeme.c_str(),operators["."])==0){
                    state=3;
                    return new Token(Period,lexeme,col,row);
                }
                else if (strcmp(lexeme.c_str(),operators["*"])==0){
                    state=3;
                    return new Token(Multiplication,lexeme,col,row);
                }
                else if (strcmp(lexeme.c_str(),operators["-"])==0){
                    state=3;
                    return new Token(Substraction,lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators["="])==0){
                    state=3;
                    return new Token(Equal,lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators["\n"])==0){
                    state=3;
                    return new Token(Eos,lexeme,col, row );
                }
                else if (strcmp(lexeme.c_str(),operators["("])==0){
                    state=3;
                    return new Token(OpenParenthesis, lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators[")"])==0){
                    state=3;
                    return new Token(CloseParenthesis,lexeme,col,row );
                }

                else if (strcmp(lexeme.c_str(),operators[":"])==0){
                    state=3;
                    return new Token(Colon,lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators["["])==0){
                    state=3;
                    return new Token(OpenBracket,lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators["]"])==0){
                    state=3;
                    return new Token(CloseBracket,lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators[","])==0){
                    state=3;
                    return new Token(Coma,lexeme,col,row );
                }
                else if (strcmp(lexeme.c_str(),operators["^"])==0){
                    state=3;
                    return new Token(Exponentiation,lexeme,col,row );
                }
                break;
           case 6:
                if(isdigit(symbol))
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                }else if(symbol=='.')
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 7;
                }
                else{
                    state=3;
                    return new Token(EnteroNumber,lexeme,col,row);
                }
                break;
            case 7:
                if (isdigit(symbol))
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                    state = 8;
                }
                else
                    throw invalid_argument("Se esperaba digito");
                    //throw new LexicalException("Se esperaba digito");
                break;
            case 8:
                if (isdigit(symbol))
                {
                    lexeme += symbol;
                    symbol = GetNextSymbol();
                }
                else{
                    state=3;
                    return new Token(RealNumber,lexeme,col,row);
                }
                break;
            case 9:
                if(symbol != '\"' )
                {
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                }
                else if(symbol == '\"'){
                    symbol = GetNextSymbol();
                    state =10;
                }else
                    throw invalid_argument("No se cerro string. Columna: "+to_string(col)+" Fila: "+to_string(row));

                break;
            case 10:
                state=3;
                return new Token(Str,lexeme,col,row);
            case 11:
                if(symbol== '='){
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state=12;
                }
                else{
                    state=3;
                    return new Token(GreaterThan,lexeme,col,row);
                }
                break;
            case 12:
                state=3;
                return new Token(GreaterEqual,lexeme,col,row);
            case 13:
                if(symbol == '>'){
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state=14;
                }
                else if(symbol == '-'){
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state=15;
                }
                else if(symbol == '='){
                    lexeme+=symbol;
                    symbol = GetNextSymbol();
                    state=16;
                }
                else{
                    state=3;
                    return new Token(LessThan,lexeme,col,row);
                }
                break;
            case 14:
                    state=3;
                    return new Token(NotEqual,lexeme,col,row);
            case 15:
                    state=3;
                    return new Token(ValueAllocation,lexeme,col,row);
            case 16:
                    state=3;
                    return new Token(LessEqual,lexeme,col,row);
            case 17:
                    if(symbol=='>'){
                        symbol=GetNextSymbol();
                        state=0;
                    }
                    else{
                        string error="No se reconoce simbolo ";
                        error+=symbol;
                        throw invalid_argument(error+" Columna: "+to_string(col)+" Fila: "+to_string(row));
                    }
                    break;
           case 18:
                if(symbol == '/')
                {
                    if(lexeme.length()>0)
                        lexeme="";
                    symbol=GetNextSymbol();
                    state =19;
                }
                else if(symbol == '*'){
                    if(lexeme.length()>0)
                        lexeme="";
                    symbol=GetNextSymbol();
                    state =22;
                }
                else if (strcmp(lexeme.c_str(),operators["/"])==0){
                    state=3;
                    return new Token(RealDivision,lexeme,col,row );
                }
                break;
           case 19:
                if(symbol != '\n'){
                    symbol=GetNextSymbol();
                }
                else{
                    symbol=GetNextSymbol();
                    state=3;
                }
                break;
           case 20:
                lexeme += symbol;
                symbol = GetNextSymbol();
                if(symbol != '\''){
                    throw invalid_argument("No se envio un caracter. Columna: "+to_string(col)+" Fila: "+to_string(row));
                }
                else{
                    lexeme+=symbol;
                    symbol=GetNextSymbol();
                    state = 21;
                }
                break;
            case 21:
                    state = 3;
                    return new Token(Character,lexeme,col,row);
                    break;
            case 22:
                if(symbol=='*'){
                    symbol=GetNextSymbol();
                    state=23;
                }
                else{
                    symbol=GetNextSymbol();
                }
                break;
            case 23:
                if(symbol=='/'){
                    symbol=GetNextSymbol();
                    state =3;
                }
                else{
                    symbol=GetNextSymbol();
                    state=22;
                }

        }
    }

}


Lexer::~Lexer()
{

}

