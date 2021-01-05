#include <stdio.h>
#include <stdlib.h>
#define MAX 20

/*o espaço de busca inicialmente é a sequência inteira de elementos dada pelo vetor
ordenado (vamos assumir ordenação crescente).
- a cada passo, o algoritmo compara o valor buscado com o elemento no ponto médio ou
central do vetor. Por exemplo, um vetor de 10 posições com índices de 0 a 9 tem como ponto
médio/central a posição 4, pois a parte inteira da divisão (0+9)/2 é igual a 4.
- com base no resultado desta comparação, o algoritmo define o próximo passo:
- se o elemento no ponto médio do vetor for igual ao valor buscado, a busca termina
com sucesso
- senão, o algoritmo divide o espaço de busca em dois:
- se o valor buscado for menor que o elemento no ponto médio do vetor, a
busca é repetida à esquerda deste elemento (na metade anterior ao ponto médio)
- por outro lado, se o valor buscado for maior que o elemento no ponto
médio do vetor, a busca continua à direita deste elemento (na metade posterior ao
ponto médio)
O algoritmo repete este processo de divisão do espaço de busca até que o ponto central seja o
número que ele está procurando, ou que o vetor tenha apenas uma posição que não seja o número
buscado.
Implemente em C o algoritmo de busca binária utilizando recursividade. O protótipo da função a ser
implementada deverá ser:
int buscaBinaria (int *vetor, int tamVetor, int valor, int limInf, int limSup)
onde tamVetor especifica o tamanho do vetor passado por referência (primeiro argumento),
valor é o número a ser buscado no vetor, e limInf e limSup são os limites inferior e superior da
busca, os quais inicialmente serão iguais a 0 e N-1, onde N é o número de elementos no vetor.
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

