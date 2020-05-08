// Add your program here!
//
//
#include <stdio.h>

/*
 *  * The power function takes in the base, and the power and calculates the math,
 *   * then returns the result back to the main function to then print.
 *    */
double power(double base, double n) {
    double result = 1;
    double i = 1;

    for (i = 1; i <= n; i++) {
        result = result * base;
    }
    return result;
}
/*
 *  * The main function drives the program. The power function is called here,
 *   * the math is calculated in the power function, and the result is printed here.
 *    * A while loop is used here
 *     */
int main () {
    /*
 *      * Initializing the base, n, result, i for iteration, and maxPower variables
 *           * to pass into the power function.
 *                */
    double base = 2;
    double n = 1;
    double result = 1;
    double i = 1;
    double maxPower = 10;

    while (n <= maxPower) {
        result = power(base, n);
        n++;
        printf("%.2f\n", result);
    }
    return 0;
}
