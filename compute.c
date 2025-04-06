#include <stdio.h>
#include <math.h>

float xVal = 0.0;
float yVal = 0.0;
FILE *dumpFile;

void compute_result(char varName[], int xIndex, int yIndex) {
    // Simulate xVal and yVal (replace with actual input lookup if needed)
    xVal = (float)xIndex;
    yVal = (float)yIndex;

    float result = sqrt(xVal * xVal + yVal * yVal);
    printf("Result of %s = sqrt(%f^2 + %f^2): %.2f\n", varName, xVal, yVal, result);
    fprintf(dumpFile, "[RESULT] %s = sqrt(%f^2 + %f^2) = %.2f\n", varName, xVal, yVal, result);
}
