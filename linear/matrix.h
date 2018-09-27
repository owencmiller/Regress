
#ifndef MATRIX
#define MATRIX

typedef struct{
    int height;
    int width;
    float **mat;
}matrix, *Matrix;

Matrix addMatrix(Matrix m1, Matrix m2);
Matrix subMatrix(Matrix m1, Matrix m2);
Matrix mulMatrix(Matrix m1, Matrix m2);
void transpose(Matrix m);

Matrix createMatrix(int height, int width, float mat[][width]);
void free2DArray(Matrix m);
void deleteMatrix(Matrix m);
void printMatrix(Matrix m);

#endif
