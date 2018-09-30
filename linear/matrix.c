#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "matrix.h"

void addMatrixConst(Matrix m, double num){
    for(int i = 0; i < m->height; i++){
        for(int j = 0; j < m->width; j++){
            m->mat[i][j] += num;
        }
    }
}

void subMatrixConst(Matrix m, double num){
    for(int i = 0; i < m->height; i++){
        for(int j = 0; j < m->width; j++){
            m->mat[i][j] -= num;
        }
    }
}

void mulMatrixConst(Matrix m, double num){
    for(int i = 0; i < m->height; i++){
        for(int j = 0; j < m->width; j++){
            m->mat[i][j] *= num;
        }
    }
}


Matrix mulMatrix(Matrix m1, Matrix m2){
    if(m1->width != m2->height){
        printf("Unable to print matricies of dimension: %dx%d and %dx%d\n", m1->height, m1->width, m2->height, m2->width);
        return 0;
    }
    int height = m1->height;
    int width = m2->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = 0;
            for(int k = 0; k < m1->width; k++){
                data[i][j] += m1->mat[i][k] * m2->mat[k][j];
            }
        }
    }

    return createMatrix(height, width, data);
}

void transpose(Matrix m){
    int heightT = m->width;
    int widthT = m->height;
    double **data = malloc(sizeof(double**) * heightT);
    for(int i = 0; i < heightT; i++){
        data[i] = malloc(sizeof(double) * widthT);
    }
    for(int i = 0; i < heightT; i++){
        for(int j = 0; j < widthT; j++){
            data[i][j] = m->mat[j][i];
        }
    }
    free2DArray(m);
    m->mat = data;
    m->height = heightT;
    m->width = widthT;
}

Matrix addMatrix(Matrix m1, Matrix m2){
    if((m1->height != m2->height) && (m1->width != m2->width)){
        printf("Unable to add matricies of different dimensions: %dx%d and %dx%d\n", m1->height, m1->width, m2->height, m2->width);
        return 0;
    }
    int height = m1->height;
    int width = m1->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = m1->mat[i][j] + m2->mat[i][j];
        }
    }
    return createMatrix(height, width, data);
}

Matrix subMatrix(Matrix m1, Matrix m2){
    if((m1->height != m2->height) && (m1->width != m2->width)){
        printf("Unable to add matricies of different dimensions: %dx%d and %dx%d\n", m1->height, m1->width, m2->height, m2->width);
        return 0;
    }
    int height = m1->height;
    int width = m1->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = m1->mat[i][j] - m2->mat[i][j];
        }
    }
    return createMatrix(height, width, data);
}

Matrix createMatrix(int height, int width, double mat[][width]){
    Matrix m = malloc(sizeof(matrix));
    m->height = height;
    m->width = width;
    m->mat = malloc(sizeof(double**) * height);
    
    for(int i = 0; i < height; i++){
        m->mat[i] = malloc(sizeof(double) * width);
        for(int j = 0; j < width; j++){
            m->mat[i][j] = mat[i][j];
        }
    }

    return m;
}

Matrix createRandMatrix(int height, int width){
    double data[height][width];
    srand(time(0));
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = ((double)rand()) / ((double)RAND_MAX);
        }
    }
    return createMatrix(height, width, data);
}

void freeMatrix(Matrix m){
    if(!m){
        return;
    }
    printf("Freeing matrix of size: %dx%d\n", m->height, m->width);
    free2DArray(m);
    free(m);
}

void free2DArray(Matrix m){
    for(int i = 0; i < m->height; i++){
        free(m->mat[i]);
    }
    free(m->mat); 
}

void printMatrix(Matrix m){
    if(!m){
        return;
    }
    for(int i = 0; i < m->height; i++){
        printf("[");
        for(int j = 0; j < m->width; j++){
            if(j == (m->width-1)){
                printf("%.3f", m->mat[i][j]);
            }else{
                printf("%.3f ", m->mat[i][j]);
            }
        }
        printf("]\n");
    }
}
