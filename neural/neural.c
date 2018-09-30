#include <stdio.h>
#include <stdlib.h>
#include "neural.h"
#include "../linear/linear.h"


Network createNetwork(Matrix inputs, Matrix outputs, int numLayers, int layers[numLayers]){
    Network n = malloc(sizeof(network));
    n->inputs = inputs;
    n->outputs = outputs;
    n->weights = malloc(sizeof(Matrix) * (numLayers+1));
    for(int i = 0; i < (numLayers+1); i++){
        if(i == 0){
            n->weights[i] = createRandMatrix(inputs->width, layers[i]);
        }else if(i == numLayers){
            n->weights[i] = createRandMatrix(layers[i-1], outputs->width);
        }else{
            n->weights[i] = createRandMatrix(layers[i-1], layers[i]);
        }
    }
    n->numLayers = numLayers+1;
    return n;
}

void freeNetwork(Network n){
    for(int i = 0; i < n->numLayers; i++){
        freeMatrix(n->weights[i]);
    }
    free(n->weights);
    freeMatrix(n->inputs);
    freeMatrix(n->outputs);
    free(n);
}

