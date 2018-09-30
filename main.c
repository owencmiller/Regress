#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./neural/neural.h"
#include "./linear/linear.h"

int main(){
    double data1[][3] = {{1, 0, 1}, {0, 0, 0}, {1, 1, 1}};
    double data2[][2] = {{3, 20}, {4, 0}, {5, 13}};
    Matrix inputs = createMatrix(3, 3, data1);
    Matrix outputs = createMatrix(3, 2, data2);
    
    int numLayers = 1;
    int layers[] = {2};

    Network n = createNetwork(inputs, outputs, numLayers, layers);
    printMatrix(n->weights[0]);
    printf("\n");
    printMatrix(n->weights[1]);
    
    // clean up
    freeNetwork(n);

    return 0;
}
