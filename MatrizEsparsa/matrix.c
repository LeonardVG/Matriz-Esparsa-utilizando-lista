#include "matrix.h"

Matrix *criaNo(int i, int j, float valor) {
    Matrix *novo = (Matrix *)malloc(sizeof(Matrix));
    novo->line = i;
    novo->column = j;
    novo->info = valor;
    novo->right = novo; 
    novo->below = novo;  
    return novo;
}

Matrix* matrix_create( void ){
  int linha, coluna;
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &linha, &coluna);
  
    Matrix *head = criaNo(0, 0, 0); // Nó cabeça principal (0 0)
    Matrix *atual_linha = head;
    Matrix *atual_coluna = head;

    // Criando nós cabeça para linhas
    for (int i = 1; i <= linha; i++) {
        atual_linha->below = criaNo(i, 0, 0);
        atual_linha = atual_linha->below;
        atual_linha->below = head; // Conecta de volta ao nó cabeça
    }

    // Criando nós cabeça para colunas
    for (int j = 1; j <= coluna; j++) {
        atual_coluna->right = criaNo(0, j, 0);
        atual_coluna = atual_coluna->right;
        atual_coluna->right = head; // Conecta de volta ao nó cabeça
    }

  int lin, col;
    float valor;
    printf("Digite a linha, coluna e valor (valor = 0 para encerrar):\n");
    do{
        scanf("%d %d %f", &lin, &col, &valor);
     if ((lin > 0 && lin<=linha ) && ( col > 0 && col <= coluna) && valor != 0) {
           matrix_setelem(head, lin, col, valor);
         
       }
    }while(valor!=0 );

    return head;
}

void matrix_setelem( Matrix* m, int x, int y, float elem ){

    Matrix *ref_linha = m;
    Matrix *ref_coluna = m;

    while (ref_linha->line != x) {
        ref_linha = ref_linha->below;       //percorrendo até chegar na linha dessejada
    }

    while (ref_coluna->column != y) {
        ref_coluna = ref_coluna->right;     //percorrendo até chegar na coluna dessejada
    }

    if (ref_linha && ref_coluna) {        //se não são nulos///////REVER DEPOIS
        Matrix *novo = criaNo(x, y, elem);
        Matrix *percorre_line = ref_linha;
      
        while (percorre_line->right != ref_linha && percorre_line->right->column < y) {
            percorre_line = percorre_line->right;
        }
                   //se já existe:
          if (percorre_line->right != ref_linha && percorre_line->right->column == y) {
        
        percorre_line->right->info = elem;  // Se sim, apenas atualiza o valor de info
    } else {
        novo->right = percorre_line->right;
        percorre_line->right = novo;
      }
      
        Matrix *percorre_col = ref_coluna;
        while (percorre_col->below != ref_coluna && percorre_col->below->line < x) {
            percorre_col = percorre_col->below;
        }
      
     if (percorre_col->below != ref_coluna && percorre_col->below->line == x) {
       
       percorre_col->below->info = elem;   // atualiza o valor de info 
       free(novo);                        //libera memoria do nó criado
       
      } else {
      
        novo->below = percorre_col->below;
        percorre_col->below = novo;
      }
      
    }
}

void matrix_print( Matrix* m ){
  if (m != NULL){
    Matrix *percorre_line = m->below;
    while (percorre_line != m) {
        Matrix *atual = percorre_line->right;
        while (atual != percorre_line) {
            printf("%d %d %.2f\n", atual->line, atual->column, atual->info);
            atual = atual->right;
        }
        //printf("\n");
        percorre_line = percorre_line->below;
    }
  }else{ printf("matriz nula");}
}

void matrix_destroy( Matrix* m ){
 Matrix *referencia = m->below;             // começa na linha 1, coluna 0
    
     while (referencia != m) {
        Matrix *atual = referencia->right;  // atual começa no primeiro elemento da matriz
        while (atual != referencia) {
            Matrix *temp = atual;
            atual = atual->right;
            free(temp);                     // Liberando os nós da linha
        }
        Matrix *temp2 = referencia;
        referencia = referencia->below; // referencia vai para a linha de baixo
        free(temp2);                   // Libera o nó cabeça da linha
    }
 // todas as linhas foram liberadas menos a primeira linha,com colunas cabeças
    Matrix *atual2 = m->right;
    while (atual2 != m) {
        Matrix *tempCol = atual2;
        atual2 = atual2->right;
        free(tempCol); // Liberando os nós cabeça da primeira linha coluna a coluna
    }

    free(m); // Liberando o nó cabeça principal
  
}

float matrix_getelem( Matrix* m, int x, int y ){

    Matrix *ref_linha = m;
    Matrix *ref_coluna = m;

    
    while (ref_linha->line != x) {       //procurando o nócabeça da linha
        ref_linha = ref_linha->below;
    }
///////////////////rever depois as condições anteriores/////////////////////////////
    
    while (ref_coluna->column != y) {    //procurando o nócabeã da 
        ref_coluna = ref_coluna->right;
    }

    
    Matrix *percorre_line = ref_linha->right; 
  
// Percorrer a matriz para encontrar o elemento solicitado
  
    while (percorre_line != ref_linha && percorre_line->column <= y) {
        if (percorre_line->column == y) {
            return percorre_line->info; // se o elemento existe
        }
        percorre_line = percorre_line->right;
    }

    return 0.0; // Elemento não encontrado saida = zero
}


Matrix* create_result( int linha, int coluna ){
  
    Matrix *head = criaNo(0, 0, 0); // Nó cabeça principal (0 0)
    Matrix *atual_linha = head;
    Matrix *atual_coluna = head;

    // Criando nós cabeça para linhas
    for (int i = 1; i <= linha; i++) {
        atual_linha->below = criaNo(i, 0, 0);
        atual_linha = atual_linha->below;
        atual_linha->below = head; // Conecta de volta ao nó cabeça
    }

    // Criando nós cabeça para colunas
    for (int j = 1; j <= coluna; j++) {
        atual_coluna->right = criaNo(0, j, 0);
        atual_coluna = atual_coluna->right;
        atual_coluna->right = head; // Conecta de volta ao nó cabeça
    }


    return head;
}

int retorna_tam_linha(Matrix *m){
Matrix *cont;
int tam =0;  
  for(cont = m->below;cont != m; cont = cont->below){
       tam++;
     }

  return tam;
}

int retorna_tam_coluna(Matrix *m){

  Matrix *cont;
int tam =0;  
  for(cont = m->right; cont != m; cont=cont->right){
       tam++;
     }

  return tam;
  
}


Matrix* matrix_add(Matrix* m, Matrix* n) {

  int tam_linM,tam_colM,tam_linN,tam_colN;
  tam_linM = retorna_tam_linha(m);
  tam_colM = retorna_tam_coluna(m);
  tam_linN = retorna_tam_linha(n);
  tam_colN = retorna_tam_coluna(n);

  //printf("\ntam M:%d %d | tam N: %d %d\n",tam_linM,tam_colM,tam_linN,tam_colN);
  
    if (tam_linM != tam_linN || tam_colM != tam_colN) {
        printf("Erro: Matrizes com dimensões diferentes.\n");
        return NULL;
    }                       
    int lin = tam_linM;
    int col = tam_colM;

  
    Matrix *result = create_result(lin, col); 
  
    for (int i = 1; i <= lin; i++) {
        for (int j = 1; j <= col; j++) {
            float soma = matrix_getelem(m, i, j) + matrix_getelem(n, i, j);
           
            if (soma != 0) {
                matrix_setelem(result, i, j, soma);
            }
        }
    }

    return result;
}


Matrix* matrix_transpose( Matrix* m ){

    int lin = retorna_tam_linha(m);
    int col = retorna_tam_coluna(m);

  Matrix *mT = create_result(lin,col); //criando a matriz só com a linha e coluna de cabeças

    for (int i = 1; i <= lin; i++) {
        for (int j = 1; j <= col; j++) {
            float valor = matrix_getelem(m, i, j);
            if (valor != 0) {
                matrix_setelem(mT, j, i, valor);
            }
        }
    }

    return mT;
}


Matrix* matrix_multiply(Matrix* m, Matrix* n) {

 int tam_linM,tam_colM,tam_linN,tam_colN;
  tam_linM = retorna_tam_linha(m);
  tam_colM = retorna_tam_coluna(m);
  tam_linN = retorna_tam_linha(n);
  tam_colN = retorna_tam_coluna(n);
  
    if (tam_colM != tam_linN) {
        printf("Erro: Matrizes não possuem dimenções validas\n");
        return NULL;
    }

    int quant = tam_colM;  //numero de vezes q tem q multiplicar 
    int linha = tam_linM;
    int coluna = tam_colN;
    

    Matrix *resultado = create_result(linha,coluna); 

    for (int i = 1; i <= linha; i++) {
        for (int j = 1; j <= coluna; j++) {
            float soma = 0;
            for (int k = 1; k <= quant; k++) {
                soma += matrix_getelem(m, i, k) * matrix_getelem(n, k, j);
            }
            if (soma != 0) {
                matrix_setelem(resultado, i, j, soma);
            }
        }
    }

    return resultado;
}