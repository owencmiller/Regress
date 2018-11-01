
#ifndef MATRIX
#define MATRIX

typedef struct{
    int height;
    int width;
    double **mat;
}matrix, *Matrix;

Matrix addMatrixConst(Matrix m, double num);
Matrix subMatrixConst(Matrix m, double num);
Matrix mulMatrixConst(Matrix m, double num);
Matrix divMatrixConst(Matrix m, double num);

Matrix addMatrix(Matrix m1, Matrix m2);
Matrix subMatrix(Matrix m1, Matrix m2);
Matrix mulMatrix(Matrix m1, Matrix m2);
Matrix expMatrix(Matrix m);
Matrix logMatrix(Matrix m);
Matrix recipMatrix(Matrix m);

void insertCol(Matrix m, double data[], int size, int colNum);
void transpose(Matrix m);

Matrix createMatrix(int height, int width, double mat[][width]);
Matrix createRandMatrix(int height, int width);
Matrix duplicateMatrix(Matrix m);
void free2DArray(Matrix m);
void freeMatrix(Matrix m);
void printMatrix(Matrix m);

#endif
