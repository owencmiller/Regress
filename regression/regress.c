#include <stdio.h>
#include "regress.h"
#include "../linear/linear.h"

Matrix linearRegression(Matrix inputs, Matrix expected){

    Matrix coefficients = createRandMatrix(inputs->width, 1);

    Matrix hypotheses = mulMatrix(inputs, coefficients);

    return mulMatrix(inputs, coefficients);
}
