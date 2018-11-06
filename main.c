#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./neural/neural.h"
#include "./linear/linear.h"
#include "./regression/regress.h"

int main(){
    double data1[][1] = {{0}, {1}};
    Matrix inputs = createMatrix(2, 1, data1);
    double data2[][1] = {{1}, {0}};
    Matrix expected = createMatrix(2, 1, data2);

    linearRegression(inputs, expected, false);

    return 0;
}
