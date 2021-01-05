#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*o espa�o de busca inicialmente � a sequ�ncia inteira de elementos dada pelo vetor
ordenado (vamos assumir ordena��o crescente).
- a cada passo, o algoritmo compara o valor buscado com o elemento no ponto m�dio ou
central do vetor. Por exemplo, um vetor de 10 posi��es com �ndices de 0 a 9 tem como ponto
m�dio/central a posi��o 4, pois a parte inteira da divis�o (0+9)/2 � igual a 4.
- com base no resultado desta compara��o, o algoritmo define o pr�ximo passo:
- se o elemento no ponto m�dio do vetor for igual ao valor buscado, a busca termina
com sucesso
- sen�o, o algoritmo divide o espa�o de busca em dois:
- se o valor buscado for menor que o elemento no ponto m�dio do vetor, a
busca � repetida � esquerda deste elemento (na metade anterior ao ponto m�dio)
- por outro lado, se o valor buscado for maior que o elemento no ponto
m�dio do vetor, a busca continua � direita deste elemento (na metade posterior ao
ponto m�dio)
O algoritmo repete este processo de divis�o do espa�o de busca at� que o ponto central seja o
n�mero que ele est� procurando, ou que o vetor tenha apenas uma posi��o que n�o seja o n�mero
buscado.
Implemente em C o algoritmo de busca bin�ria utilizando recursividade. O prot�tipo da fun��o a ser
implementada dever� ser:
int buscaBinaria (int *vetor, int tamVetor, int valor, int limInf, int limSup)
onde tamVetor especifica o tamanho do vetor passado por refer�ncia (primeiro argumento),
valor � o n�mero a ser buscado no vetor, e limInf e limSup s�o os limites inferior e superior da
busca, os quais inicialmente ser�o iguais a 0 e N-1, onde N � o n�mero de elementos no vetor.
*/

int buscaBinaria (int *vetor, int tamVetor, int valor, int limInf, int limSup){
    int ptoMedio = ((limInf + limSup)/2);
    //printf("\n\nponto medio: %d\n", ptoMedio);
    //printf("tamVetor: %d\n", tamVetor);
    //printf("valor: %d\n", valor);
    if(vetor[ptoMedio] == valor){
        return ptoMedio;
    }
    else if(ptoMedio == limInf || ptoMedio == limSup){ //caso atinja os extremos
        return -1;
    }
    else if(vetor[ptoMedio] < valor){
        return buscaBinaria(vetor, tamVetor, valor, ptoMedio, limSup);
    }
    else if(vetor[ptoMedio] > valor){
        return buscaBinaria(vetor, tamVetor, valor, limInf, ptoMedio);
    }
}

int main() {
    int valor;
    int vetor[MAX] = {1,2,3,4,6,7,9,11,12,14,15,16,17,19,33,34,43,45,55,66};
    int i;
    int posicao;

    printf("Vetor: ");
    for (i=0; i<MAX; i++)
        printf("%d  ",vetor[i]);
    printf("\n\n");

    printf("Digite um numero: ");
    scanf("%d", &valor);

    posicao = buscaBinaria(vetor, MAX, valor, 0, MAX);

    if (posicao == -1) {
        printf("O numero nao foi encontrado no vetor\n");
    }
    else {
        printf("Numero encontrado na posicao : %d\n",posicao+1);
    }

    return 0;
}

