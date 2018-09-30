#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "./neural/neural.h"
#include "./linear/linear.h"

int main(){
    double data1[][2] = {{1, 1}, {0, 0}};
    double data2[][1] = {{3}, {4}};
    Matrix inputs = createMatrix(2, 2, data1);
    Matrix outputs = createMatrix(2, 1, data2);
    
    int numLayers = 0;
    int layers[0];

    Network n = createNetwork(inputs, outputs, numLayers, layers);
    printf("Inputs:\n");
    printMatrix(n->inputs);
    printf("Weights:\n");
    printMatrix(n->weights[0]);
    printf("New Output:\n");
    printMatrix(feedforward(n));

    // clean up
    freeNetwork(n);

    return 0;
}
