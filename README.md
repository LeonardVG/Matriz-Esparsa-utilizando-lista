# Matriz-Esparsa-utilizando-lista
Existem muitas situações onde encontramos esse tipo de matrizes, por exemplo, em Aprendizado de
Máquina e simulações da realidade com o uso de equações da física como aerodinâmica e
termodinâmica.

Para estas matrizes, podemos economizar um espaço significativo de memória se apenas os termos
diferentes de zero forem armazenados, pois elas podem ser gigantescas, porém só uma pequena
porcentagem delas é diferente de zero. Por exemplo, imagine que as colunas e linhas são todas as
pessoas do planeta e marcamos com 1 a linha e coluna onde as duas pessoas se conhecem.

As operações usuais sobre estas matrizes (somar, multiplicar, inverter, pivotar) também podem ser
feitas em tempo muito menor se não armazenarmos as posições que contém zeros. 
Uma maneira eficiente de representar estruturas com tamanho variável e/ou desconhecido é através de alocação
encadeada, utilizando listas. 

O objetivo deste trabalho é usar esta representação para armazenar e
manipular as matrizes esparsas. Cada coluna da matriz será representada por uma lista linear
circular com uma célula cabeça. Da mesma maneira, cada linha da matriz também será representada
por uma lista linear circular com uma célula cabeça. Cada célula da estrutura, além das
células-cabeça, representará os termos diferentes de zero da matriz e devem ter o seguinte tipo:

struct matrix {

struct matrix* right;

struct matrix* below;

int line;

int column;

float info;

}

typedef struct matrix Matrix;

O campo below deve ser usado para apontar o próximo elemento diferente de zero na mesma
coluna. O campo right deve ser usado para apontar o próximo elemento diferente de zero na mesma
linha. Dada uma matriz A, para um valor A(i, j) diferente de zero, deverá haver uma célula com o
campo info contendo A(i, j), o campo line contendo i e o campo column contendo j. Esta célula
deverá pertencer à lista circular da linha i e também deverá pertencer à lista circular da coluna j. Ou
seja, cada célula pertencerá a duas listas ao mesmo tempo. Para diferenciar as células cabeça,
coloque -1 nos campos line e column destas células. Importante: É obrigatório o uso de alocação
dinâmica de memória para implementar as listas de adjacência que representam as matrizes!
