#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include "regress.h"
#include "../linear/linear.h"

// Insert ones for theta 0
void insertOnes(Matrix inputs){
    int height = inputs->height;
    double ones[height];
    for(int i = 0; i < height; i++){
        ones[i] = 1;
    }
    insertCol(inputs, ones, height, 0);
}

// Implementation of linear hypothesis: X*theta
Matrix linearHypothesis(Matrix inputs, Matrix coefficients){
    Matrix hypo = mulMatrix(inputs, coefficients);
    return hypo;
}

Matrix logisticHypothesis(Matrix inputs, Matrix coefficients){
    Matrix hypo = linearHypothesis(inputs, coefficients);
    return recipMatrix(addMatrixConst(expMatrix(mulMatrixConst(hypo, -1)), 1));
}

Matrix logisticCostFunction(Matrix inputs, Matrix coefficients, Matrix expected){
    Matrix hypo = logisticHypothesis(inputs, coefficients);
    Matrix first = mulMatrix(mulMatrixConst(transpose(inputs), -1), logMatrix(hypo));
    Matrix second = mulMatrix(transpose(subConstMatrix(1, inputs)), logMatrix(subConstMatrix(1, hypo)));
    return divMatrixConst(subMatrix(first, second), inputs->height);
}

// Implementation of linear cost function: (1/2m)*(X*theta - y)'*(X*theta - y)
Matrix linearCostFunction(Matrix inputs, Matrix coefficients, Matrix expected){
    Matrix hypo = linearHypothesis(inputs, coefficients);
    Matrix diff = subMatrix(hypo, expected);
    Matrix diffTrans = transpose(diff);
    Matrix div = divMatrixConst(mulMatrix(diffTrans, diff), 2*inputs->height);
    return div;
}

// Implementation of linear gradient descent:  theta -= (alpha/m)*X'*(X*theta - y)
Matrix linearGradientDescent(Matrix inputs, Matrix coefficients, Matrix expected, double alpha){
    Matrix hypo = linearHypothesis(inputs, coefficients);
    Matrix diff = subMatrix(hypo, expected);
    Matrix inputTrans = transpose(inputs);
    Matrix change = mulMatrix(inputTrans, diff);
    Matrix mul = mulMatrixConst(change, alpha);
    Matrix div = divMatrixConst(mul, inputs->height);
    Matrix sub = subMatrix(coefficients, div);
    freeMatrix(coefficients);
    return sub;
}

// Implementation of logistic gradient descent:  theta -= (alpha/m)*X'*(X*theta - y)
Matrix logisticGradientDescent(Matrix inputs, Matrix coefficients, Matrix expected, double alpha){
    Matrix hypo = logisticHypothesis(inputs, coefficients);
    Matrix diff = subMatrix(hypo, expected);
    Matrix inputTrans = transpose(inputs);
    Matrix change = mulMatrix(inputTrans, diff);
    Matrix mul = mulMatrixConst(change, alpha);
    Matrix div = divMatrixConst(mul, inputs->height);
    Matrix sub = subMatrix(coefficients, div);
    freeMatrix(coefficients);
    return sub;
}

// Perform linear regression
Matrix linearRegression(Matrix inputs, Matrix expected, bool print){

    double alpha = .01;
    double cost = 0;
    int counter = 0;

    insertOnes(inputs);
    Matrix coefficients = createRandMatrix(inputs->width, 1);
    clock_t t = clock();

    do{
        Matrix costMat = linearCostFunction(inputs, coefficients, expected);
        cost = costMat->mat[0][0];
        if(print){
            printf("%0.11f\n", cost);
        }
        coefficients = linearGradientDescent(inputs, coefficients, expected, alpha);
        counter++;
    }while(cost > .00000001);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Finished in %f seconds with %d iterations:\n", time_taken, counter);
    printMatrix(coefficients);
    return coefficients;
}

// Perform logistic regression
Matrix logisticRegression(Matrix inputs, Matrix expected, bool print){

    double alpha = .01;
    double cost = 0;
    int counter = 0;

    insertOnes(inputs);
    Matrix coefficients = createRandMatrix(inputs->width, 1);
    clock_t t = clock();

    do{
        Matrix costMat = logisticCostFunction(inputs, coefficients, expected);
        cost = costMat->mat[0][0];
        if(print){
            printf("%0.11f\n", cost);
        }
        coefficients = logisticGradientDescent(inputs, coefficients, expected, alpha);
        counter++;
    }while(cost > .0000001);

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("Finished in %f seconds with %d iterations:\n", time_taken, counter);
    printMatrix(coefficients);
    return coefficients;
}
