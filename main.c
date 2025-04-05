#include <stdio.h>
#include "compute.h"

extern int yylex();
extern double xVal, yVal;
void execute_instruction(double x, double y);

int main() {
    int token;

    printf("Enter expression like: compute z = sqrt(x3^2 + y4^2)\n> ");

    while ((token = yylex())) {
        if (token == COMPUTE) {
            token = yylex(); // z
            if (token == Z) {
                token = yylex(); // =
                if (token == EQUALS) {
                    token = yylex(); // sqrt
                    if (token == SQRT) {
                        yylex(); // xN
                        yylex(); // ^
                        yylex(); // 2
                        yylex(); // +
                        yylex(); // yN
                        yylex(); // ^
                        yylex(); // 2

                        execute_instruction(xVal, yVal);
                        break;
                    }
                }
            }
        }
    }

    return 0;
}
