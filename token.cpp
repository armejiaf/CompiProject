#include "token.h"

Token::Token(TokenType type, string lexeme, int column, int row)
{
    this->type=type;
    this->lexeme=lexeme;
    this->column=column;
    this->row=row;

    types[Escribir]="Escribir";
    types[Arreglo]="Arreglo";
    types[Registro]="Registro";
    types[DECLARAR]="DECLARAR";
    types[EOFi] = "EOFi";
    types[Inicio] = "Inicio";
    types[Sum]="Sum";
    types[Id] = "Id";
    types[Escriba] = "Escriba";
    types[Str] = "Str";
    types[Equal] = "Equal";
    types[Eos] = "Eos";
    types[Fin] = "Fin";
    types[Llamar] = "Llamar";
    types[HTML] = "HTML";
    types[Entero] = "Entero";
    types[Real] = "Real";
    types[Caracter] = "Caracter";
    types[Booleano] = "Booleano";
    types[Cadena] = "Cadena";
    types[OpenBracket] = "OpenBracket";
    types[CloseBracket] = "CloseBracket";
    types[Multiplication] = "Multiplication";
    types[RealDivision] = "RealDivision";
    types[Exponentiation] = "Exponentiation";
    types[Mod] = "Mod";
    types[IntegerDivision]="IntegerDivision";
    types[And] = "And";
    types[Or] = "Or";
    types[Substraction] = "Substraction";
    types[OpenParenthesis] = "OpenParenthesis";
    types[CloseParenthesis] = "CloseParenthesis";
    types[Coma] = "Coma";
    types[ValueAllocation] = "ValueAllocation";
    types[GreaterThan] = "GreaterThan";
    types[LessThan] = "LessThan";
    types[GreaterEqual] = "GreaterEqual";
    types[LessEqual] = "LessEqual";
    types[NotEqual] = "NotEqual";
    types[Si] = "Si";
    types[Sino] = "Sino";
    types[Entonces] = "Entonces";
    types[RealNumber] = "RealNumber";
    types[EnteroNumber] = "EnteroNumber";
    types[Caso] = "Caso";
    types[Mientras] = "Mientras";
    types[Haga] = "Haga";
    types[Para] = "Para";
    types[Hasta] = "Hasta";
    types[Repita] = "Repita";
    types[Procedimiento] = "Procedimiento";
    types[ParameterVariable] = "ParameterVariable";
    types[Colon] = "Colon";
    types[Lectura] = "Lectura";
    types[Escritura] = "Escritura";
    types[Archivo] = "Archivo";
    types[Secuencial] = "Secuencial";
    types[Tipo] = "Tipo";
    types[Es] = "Es";
    types[De] = "De";
    types[Como] = "Como";
    types[Abrir] = "Abrir";
    types[Cerrar] = "Cerrar";
    types[Leer] = "Leer";
    types[Period] = "Period";
    types[No]="No";
    types[Verdadero]="Verdadero";
    types[Falso]="Falso";
    types[Funcion]="Funcion";
    types[Character]="Character";
    types[EOFi] = "EOFi";
    types[Inicio] = "Inicio";
    types[Sum]="Sum";
    types[Id] = "Id";
    types[Escriba] = "Escriba";
    types[Str] = "Str";
    types[Equal] = "Equal";
    types[Eos] = "Eos";
    types[Fin] = "Fin";
    types[Llamar] = "Llamar";
    types[HTML] = "HTML";
    types[Entero] = "Entero";
    types[Real] = "Real";
    types[Caracter] = "Caracter";
    types[Booleano] = "Booleano";
    types[Cadena] = "Cadena";
    types[OpenBracket] = "OpenBracket";
    types[CloseBracket] = "CloseBracket";
    types[Multiplication] = "Multiplication";
    types[RealDivision] = "RealDivision";
    types[Exponentiation] = "Exponentiation";
    types[Mod] = "Mod";
    types[IntegerDivision]="IntegerDivision";
    types[And] = "And";
    types[Or] = "Or";
    types[Substraction] = "Substraction";
    types[OpenParenthesis] = "OpenParenthesis";
    types[CloseParenthesis] = "CloseParenthesis";
    types[Coma] = "Coma";
    types[ValueAllocation] = "ValueAllocation";
    types[GreaterThan] = "GreaterThan";
    types[LessThan] = "LessThan";
    types[GreaterEqual] = "GreaterEqual";
    types[LessEqual] = "LessEqual";
    types[NotEqual] = "NotEqual";
    types[Si] = "Si";
    types[Sino] = "Sino";
    types[Entonces] = "Entonces";
    types[RealNumber] = "RealNumber";
    types[EnteroNumber] = "EnteroNumber";
    types[Caso] = "Caso";
    types[Mientras] = "Mientras";
    types[Haga] = "Haga";
    types[Para] = "Para";
    types[Hasta] = "Hasta";
    types[Repita] = "Repita";
    types[Procedimiento] = "Procedimiento";
    types[ParameterVariable] = "ParameterVariable";
    types[Colon] = "Colon";
    types[Lectura] = "Lectura";
    types[Escritura] = "Escritura";
    types[Archivo] = "Archivo";
    types[Secuencial] = "Secuencial";
    types[Tipo] = "Tipo";
    types[Es] = "Es";
    types[De] = "De";
    types[Como] = "Como";
    types[Abrir] = "Abrir";
    types[Cerrar] = "Cerrar";
    types[Leer] = "Leer";
    types[Period] = "Period";
    types[No]="No";
    types[Verdadero]="Verdadero";
    types[Falso]="Falso";
    types[Funcion]="Funcion";
    types[Character]="Character";
    types[Retorne]="Retorne";

}

void Token::Print()
{
    cout<<"Type: "<<types[type]
          <<"\tLexeme: "<<lexeme
         <<"\tColumn: "<<column
       <<"\tRow: "<<row
       <<endl;
}

Token::~Token()
{

}

