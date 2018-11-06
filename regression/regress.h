#ifndef REGRESS
#define REGRESS

#include <stdbool.h>
#include "../linear/linear.h"

void insertOnes(Matrix inputs);
Matrix linearRegression(Matrix inputs, Matrix expected, bool print);
Matrix logisticRegression(Matrix inputs, Matrix expected, bool print);

#endif
