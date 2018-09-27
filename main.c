#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./linear/linear.h"

int main(){
    float data1[][1] = {{1}, {4}, {1}};
    float data2[][1] = {{3}, {4}, {5}, {3}};
    Matrix m1 = createMatrix(3, 1, data1);
    Matrix m2 = createMatrix(3, 1, data2);
    transpose(m1); 
    
    printf("Matrix 1 -\n");
    printMatrix(m1);
    printf("Matrix 2 -\n");
    printMatrix(m2);
    printf("Product = \n");
    Matrix m3 = mulMatrix(m1, m2);
    if(m3){
        printMatrix(m3);
        deleteMatrix(m3);
    }

    // clean up
    deleteMatrix(m1);
    deleteMatrix(m2);

    return 0;
}
