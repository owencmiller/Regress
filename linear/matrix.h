
#ifndef MATRIX
#define MATRIX

typedef struct{
    int height;
    int width;
    float **mat;
}matrix, *Matrix;

void addMatrixConst(Matrix m, float num);
void subMatrixConst(Matrix m, float num);
void mulMatrixConst(Matrix m, float num);

Matrix addMatrix(Matrix m1, Matrix m2);
Matrix subMatrix(Matrix m1, Matrix m2);
Matrix mulMatrix(Matrix m1, Matrix m2);
void transpose(Matrix m);

Matrix createMatrix(int height, int width, float mat[][width]);
Matrix createRandMatrix(int height, int width);
void free2DArray(Matrix m);
void freeMatrix(Matrix m);
void printMatrix(Matrix m);

#endif
