#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./neural/neural.h"
#include "./linear/linear.h"
#include "./regression/regress.h"

int main(){
    double data1[][2] = {{0, 0}, {1, 1}, {2, 2}};
    Matrix inputs = createMatrix(3, 2, data1);

    double newdata[] = {1,2,3};
    printMatrix(inputs);
    printf("-------------\n");
    insertCol(inputs, newdata, 3, 0);
    printMatrix(inputs);


    return 0;
}
