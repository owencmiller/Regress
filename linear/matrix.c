#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>
#include "matrix.h"

Matrix addMatrixConst(Matrix m, double num){
    int height = m->height;
    int width = m->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = m->mat[i][j] + num;
        }
    }
    return createMatrix(height, width, data);
}

Matrix subMatrixConst(Matrix m, double num){
    int height = m->height;
    int width = m->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = m->mat[i][j] - num;
        }
    }
    return createMatrix(height, width, data);
}

Matrix mulMatrixConst(Matrix m, double num){
    int height = m->height;
    int width = m->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = m->mat[i][j] * num;
        }
    }
    return createMatrix(height, width, data);
}

Matrix divMatrixConst(Matrix m, double num){
    int height = m->height;
    int width = m->width;
    double data[height][width];
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            data[i][j] = m->mat[i][j] / num;
        }
    }
    return createMatrix(height, width, data);
}


Matrix mulMatrix(Matrix m1, Matrix m2){
    if(m1->width != m2->height){
        printf("Unable to multiply matricies of dimension: %dx%d and %dx%d\n", m1->height, m1->width, m2->height, m2->width);
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
        printf("Unable to subtract matricies of different dimensions: %dx%d and %dx%d\n", m1->height, m1->width, m2->height, m2->width);
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

Matrix expMatrix(Matrix m){
  int height = m->height;
  int width = m->width;
  double data[height][width];
  for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
          data[i][j] = exp(m->mat[i][j]);
      }
  }
  return createMatrix(height, width, data);
}

Matrix logMatrix(Matrix m){
  int height = m->height;
  int width = m->width;
  double data[height][width];
  for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
          data[i][j] = log(m->mat[i][j]);
      }
  }
  return createMatrix(height, width, data);
}

Matrix recipMatrix(Matrix m){
  int height = m->height;
  int width = m->width;
  double data[height][width];
  for(int i = 0; i < height; i++){
      for(int j = 0; j < width; j++){
          data[i][j] = (1 / m->mat[i][j]);
      }
  }
  return createMatrix(height, width, data);
}

void insertCol(Matrix m, double* data, int size, int colNum){

    int height = m->height;
    int width = m->width+1;

    if(width < colNum || colNum < 0 || size != height){
        printf("--Invalid column insertion--\n");
        return;
    }
    double **newdata = malloc(sizeof(double**) * height);
    for(int i = 0; i < height; i++){
        newdata[i] = malloc(sizeof(double) * width);
    }

    // This loop repeats code so 'i' gets checked O(i) rather than O(i*j) times
    for(int i = 0; i < width; i++){
        if(i < colNum){
            for(int j = 0; j < height; j++){
                newdata[j][i] = m->mat[j][i];
            }
        }else if(i == colNum){
            for(int j = 0; j < height; j++){
                newdata[j][i] = data[j];
            }
        }else if(i > colNum){
            for(int j = 0; j < height; j++){
                newdata[j][i] = m->mat[j][i-1];
            }
        }
    }

    free2DArray(m);
    m->mat = newdata;
    m->height = height;
    m->width = width;
}

Matrix duplicateMatrix(Matrix m){
    double mat[m->height][m->width];
    for(int i = 0; i < m->height; i++){
        for(int j = 0; j < m->width; j++){
            mat[i][j] = m->mat[i][j];
        }
    }
    return createMatrix(m->height, m->width, mat);
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
    //printf("Freeing matrix of size: %dx%d\n", m->height, m->width);
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
