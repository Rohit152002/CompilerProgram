%option noyywrap

digit [0-9]+
string [a-zA-Z]+

%%
{digit} printf("Digit : %s",yytext);
{string} printf("String : %s",yytext);
%%

int main()
{
    yylex();
    return 0;
}