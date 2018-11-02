#ifndef REGRESS
#define REGRESS

#include "../linear/linear.h"

void insertOnes(Matrix inputs);
Matrix linearRegression(Matrix inputs, Matrix expected);
Matrix logisticRegression(Matrix inputs, Matrix expected);

#endif
