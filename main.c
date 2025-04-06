#include <stdio.h>
#include <stdlib.h>

extern FILE *dumpFile;
extern int yylex();

int main() {
    dumpFile = fopen("dump.txt", "w");
    if (!dumpFile) {
        printf("Error opening dump file.\n");
        return 1;
    }

    printf("Enter expression like:\ncompute z = sqrt(x3^2 + y4^2);\n\n");

    yylex();

    fclose(dumpFile);
    return 0;
}
