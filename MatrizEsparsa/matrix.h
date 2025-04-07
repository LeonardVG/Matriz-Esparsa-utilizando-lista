#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Matrix {
    int line;
    int column;
    float info;
    struct Matrix *right;
    struct Matrix *below;
} Matrix;

Matrix *criaNo(int i, int j, float valor);

Matrix* matrix_create( void );

Matrix* create_result( int linha, int coluna); //matrix_create adaptado para as operações

void matrix_setelem( Matrix* m, int x, int y, float elem );

void matrix_print( Matrix* m );

void matrix_destroy( Matrix* m );

float matrix_getelem( Matrix* m, int x, int y );

Matrix* matrix_add(Matrix* m, Matrix* n);

int retorna_tam_linha(Matrix *m);
int retorna_tam_coluna(Matrix *m);

Matrix* matrix_transpose( Matrix* m );

Matrix* matrix_multiply(Matrix* m, Matrix* n);