#include <stdio.h>
#include <math.h>

float xVal = 0.0;
float yVal = 0.0;
FILE *dumpFile;

void compute_result(char varName[], int xIndex, int yIndex) {
    // Simulate values (replace later with real input or symbol table)
    xVal = (float)xIndex;
    yVal = (float)yIndex;

    // Perform the operation
    float t1 = xVal * xVal;
    float t2 = yVal * yVal;
    float t3 = t1 + t2;
    float result = sqrt(t3);

    // Output the actual result
    printf("Result of %s = sqrt(%f^2 + %f^2): %.2f\n", varName, xVal, yVal, result);

    // Write to dump.txt
    fprintf(dumpFile, "\n[RESULT] %s = sqrt(%f^2 + %f^2) = %.2f\n", varName, xVal, yVal, result);

    // Three Address Code
    fprintf(dumpFile, "\n[THREE ADDRESS CODE]\n");
    fprintf(dumpFile, "t1 = x%d * x%d\n", xIndex, xIndex);
    fprintf(dumpFile, "t2 = y%d * y%d\n", yIndex, yIndex);
    fprintf(dumpFile, "t3 = t1 + t2\n");
    fprintf(dumpFile, "%s = sqrt(t3)\n", varName);

    // Opcodes (Simulated Instruction Representation)
    fprintf(dumpFile, "\n[OPCODES]\n");
    fprintf(dumpFile, "LOAD x%d\n", xIndex);
    fprintf(dumpFile, "MUL x%d, x%d\n", xIndex, xIndex);
    fprintf(dumpFile, "LOAD y%d\n", yIndex);
    fprintf(dumpFile, "MUL y%d, y%d\n", yIndex, yIndex);
    fprintf(dumpFile, "ADD\n");
    fprintf(dumpFile, "SQRT\n");
    fprintf(dumpFile, "STORE %s\n", varName);
}
