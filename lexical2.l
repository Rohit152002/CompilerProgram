%option noyywrap
keyword double|auto|break|struct|continue|long|switch|typeof|case
literal int|float|char|string
intNumber [-+]?[0-9]*
floatNumber [-+]?[0-9]*\.[0-9]+
validIdentifier ^[a-zA-Z_]+[a-zA-Z0-9_]
invalidIdentifier ^([^a-zA-Z]).*
%%
[\n]printf("*****");
{keyword} printf("Keyword: %s\n",yytext);
{literal} printf("Literal: %s\n",yytext);
{intNumber} printf("Integer Number: %s\n",yytext);
{floatNumber} printf("Float Number: %s\n",yytext);
{validIdentifier} printf("Valid Identifier: %s\n",yytext);
{invalidIdentifier} printf("InValid Identifier : %s\n",yytext);
%%
int main(){
    yylex();
    return 0;
}