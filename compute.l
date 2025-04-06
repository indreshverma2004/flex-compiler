%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern float xVal, yVal;
extern void compute_result(char varName[], int xIndex, int yIndex);
extern FILE *dumpFile;

char variableName[100];
int xIndex = -1, yIndex = -1;
%}

%%
"compute"              { fprintf(dumpFile, "[TOKEN] compute\n"); }
"x"[0-9]+              { xIndex = atoi(yytext + 1); fprintf(dumpFile, "[TOKEN] x%d\n", xIndex); }
"y"[0-9]+              { yIndex = atoi(yytext + 1); fprintf(dumpFile, "[TOKEN] y%d\n", yIndex); }
[a-zA-Z_][a-zA-Z0-9_]* { strcpy(variableName, yytext); fprintf(dumpFile, "[TOKEN] Variable name: %s\n", yytext); }
"="                    { fprintf(dumpFile, "[TOKEN] =\n"); }
"sqrt"                 { fprintf(dumpFile, "[TOKEN] sqrt\n"); }
"\("                   { fprintf(dumpFile, "[TOKEN] (\n"); }
"\^2"                  { fprintf(dumpFile, "[TOKEN] ^2\n"); }
"\+"                   { fprintf(dumpFile, "[TOKEN] +\n"); }
"\)"                   { fprintf(dumpFile, "[TOKEN] )\n"); }
";"                    {
                          fprintf(dumpFile, "[TOKEN] ;\n");
                          compute_result(variableName, xIndex, yIndex);
                          xIndex = -1;
                          yIndex = -1;
                        }
[ \t\n\r]+             { /* skip whitespace */ }
.                      { fprintf(dumpFile, "[ERROR] Unknown character: %s\n", yytext); }
%%

int yywrap() {
    return 1;
}
