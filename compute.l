%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "compute.h"

double xVal = 0, yVal = 0;
%}

%%

compute                     { return COMPUTE; }
z                           { return Z; }
=                           { return EQUALS; }
sqrt                        { return SQRT; }
x[0-9]+                     { sscanf(yytext + 1, "%lf", &xVal); return X; }
y[0-9]+                     { sscanf(yytext + 1, "%lf", &yVal); return Y; }
\^                          { return POWER; }
[0-9]+                      { return NUM; }
\+                          { return PLUS; }
\(                          { /* Left parenthesis — can be ignored or handled */ }
\)                          { /* Right parenthesis — can be ignored or handled */ }
;                           { return END; }
[ \t\n]                     ;
.                           { printf("Unexpected character: %s\n", yytext); exit(1); }

%%

int yywrap() {
    return 1;
}
