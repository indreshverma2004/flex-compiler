#include <stdio.h>
#include <math.h>

void execute_instruction(double xVal, double yVal) {
    double result = sqrt((xVal * xVal) + (yVal * yVal));
    printf("Result of z = sqrt(x^2 + y^2): %.2f\n", result);
}
