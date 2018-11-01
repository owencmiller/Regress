#include <stdio.h>
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
Matrix hypothesis(Matrix inputs, Matrix coefficients){
    Matrix hypo = mulMatrix(inputs, coefficients);
    return hypo;
}

// Implementation of linear cost function: (1/2m)*(X*theta - y)'*(X*theta - y)
Matrix costFunction(Matrix inputs, Matrix coefficients, Matrix expected){
    Matrix hypo = hypothesis(inputs, coefficients);
    Matrix diff = subMatrix(hypo, expected);
    Matrix diffTrans = duplicateMatrix(diff);
    transpose(diffTrans);
    Matrix cost = mulMatrix(diffTrans, diff);
    divMatrixConst(cost, 2*inputs->height);
    return cost;
}

// Implementation of linear gradient descent:  theta -= (alpha/m)*X'*(X*theta - y)
Matrix gradientDescent(Matrix inputs, Matrix coefficients, Matrix expected, double alpha){
    Matrix hypo = hypothesis(inputs, coefficients);
    Matrix diff = subMatrix(hypo, expected);
    Matrix inputTrans = duplicateMatrix(inputs);
    transpose(inputTrans);
    Matrix change = mulMatrix(inputTrans, diff);
    mulMatrixConst(change, alpha);
    divMatrixConst(change, inputs->height);
    Matrix sub = subMatrix(coefficients, change);
    freeMatrix(coefficients);
    return sub;
}

// Perform linear regression
Matrix linearRegression(Matrix inputs, Matrix expected){

    double alpha = .1;
    double cost = 0;
    int counter = 0;

    insertOnes(inputs);
    Matrix coefficients = createRandMatrix(2, 1);
    do{
        Matrix costMat = costFunction(inputs, coefficients, expected);
        cost = costMat->mat[0][0];
        printf("%f\n", cost);
        coefficients = gradientDescent(inputs, coefficients, expected, alpha);
        counter++;
    }while(cost > .000001);

    printf("Finished With:\n");
    printMatrix(coefficients);
    return coefficients;
}
