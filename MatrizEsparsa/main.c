#include "matrix.h"

int main(void) {
      /* Inicializacao da aplicacao ... */
 freopen("entrada1.txt", "r", stdin);
 
Matrix *A = matrix_create();
                           printf("\nMatriz A:\n");
matrix_print( A );
Matrix *B = matrix_create();
                           printf("\nMatriz B:\n");
matrix_print( B );
Matrix *C = matrix_add( A, B );
                          printf("\nMatriz resultante ADD:\n");
matrix_print( C );
matrix_destroy( C );
C = matrix_multiply(A,B);
                           printf("\nMatriz resultante MULT:\n");
matrix_print( C );
matrix_destroy( C );
C = matrix_transpose( A );
                           printf("\nMatriz A TRANSPOSTA:\n");
matrix_print( C );
  
matrix_destroy( C );
matrix_destroy( A );
matrix_destroy( B );
  

  /*
   clock_t start_time, end_time;
    double cpu_time_used;

    start_time = clock();
freopen("entradateste2.txt", "r", stdin);

Matrix *teste = matrix_create();
 matrix_print(teste);
 // matrix_destroy(teste);
  
  end_time = clock();

    cpu_time_used = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;

    printf("Tempo de execução para criar a matriz: %f segundos\n", cpu_time_used);
  matrix_destroy(teste);
  */
  return 0;
}