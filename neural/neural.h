#include "../linear/linear.h"

typedef struct{
    Matrix inputs;
    Matrix *weights;
    Matrix outputs;
    int numLayers;
}network, *Network;

Matrix feedforward(Network net);

Network createNetwork(Matrix inputs, Matrix outputs, int numLayers, int layers[numLayers]);
void freeNetwork(Network n);
