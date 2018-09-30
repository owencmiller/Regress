#include <stdio.h>
#include <stdlib.h>
#include "neural.h"
#include "../linear/linear.h"

Matrix feedforward(Network net){
    Matrix m = mulMatrix(net->inputs, net->weights[0]);
    for(int i = 1; i < net->numLayers+1; i++){
        m = mulMatrix(m, net->weights[i]);    
    }
    return m;
}

Network createNetwork(Matrix inputs, Matrix outputs, int numLayers, int layers[numLayers]){
    Network n = malloc(sizeof(network));
    n->inputs = inputs;
    n->outputs = outputs;
    n->weights = malloc(sizeof(Matrix) * (numLayers+1));
    if(numLayers != 0){
        for(int i = 0; i < (numLayers+1); i++){
            if(i == 0){
                n->weights[i] = createRandMatrix(inputs->width, layers[i]);
            }else if(i == numLayers){
                n->weights[i] = createRandMatrix(layers[i-1], outputs->width);
            }else{
                n->weights[i] = createRandMatrix(layers[i-1], layers[i]);
            }
        }
    }else{
        n->weights[0] = createRandMatrix(inputs->width, outputs->width);
    }
    n->numLayers = numLayers;
    return n;
}

void freeNetwork(Network n){
    for(int i = 0; i < (n->numLayers+1); i++){
        freeMatrix(n->weights[i]);
    }
    free(n->weights);
    freeMatrix(n->inputs);
    freeMatrix(n->outputs);
    free(n);
}

