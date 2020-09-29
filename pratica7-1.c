/*Leia uma matriz de 3x3 elementos com valores inteiros e:
A. Imprima na tela a matriz com formatação adequada, veja um exemplo abaixo
B. Calcule e imprima a soma da diagonal principal da matriz (no exemplo acima, o
valor de saída seria 15)
C. Encontre e imprima na tela o maior valor na matriz, bem como a linha e coluna na
qual este valor foi identificado.
Seu programa deve usar, obrigatoriamente, laços de repetição para a leitura da matriz,
bem como para solucionar o que se pede nos itens A - C. Perceba que o tamanho definido para a
matriz é pequeno (3x3) a fim de facilitar os testes, mas seu programa deve ser capaz de facilmente
estender a solução para análise de uma matriz 10x10 ou 20x20, por exemplo. Desta forma, o uso de
laços de repetição é imprescindível.*/

#include <stdio.h>
#include <limits.h>
#define TAM 3

int main (){
    int matriz[TAM][TAM], col, lin, soma=0, maior = INT_MIN, guardaLinha, guardaColuna;
    printf("Entre com uma matriz 3x3: \n");
    //lê a matriz 3x3:
    for (lin=0; lin<TAM; lin++){
       // printf("linha %d\n", lin);
        for(col=0; col<3; col++){
        //    printf("coluna %d\n", col);
            scanf("%d", &matriz[lin][col]);
        }
    }
    printf("\nA matriz digitada foi:\n");
    //A. imprime matriz com formatação adequada:
    for (lin=0; lin<TAM; lin++){
        for (col=0; col<3; col++){
            printf("%4d", matriz[lin][col]);
        }
        printf("\n");
    }

    //B. calcula e imprime a soma da diagonal principal da matriz:
    // a diagonal principal é formada pelos elementos matriz[0][0], matriz[1][1] e matriz[2][2]
    for (lin=0; lin<TAM; lin++){
        for(col=0; col<TAM; col++){
            if (lin == col){
                soma += matriz[lin][col];
            }
        }
    }
    printf("\nA soma da diagonal principal eh %d \n", soma);

    //C. encontra e imprime na tela o maior valor da matriz e sua posição
    for (lin=0; lin<TAM; lin++){
        for(col=0; col<TAM; col++){
            if (matriz[lin][col] > maior){
                maior = matriz[lin][col];
                guardaLinha = lin;
                guardaColuna = col;
            }
        }
    }

    printf("O maior elemento encontrado na matriz foi %d na linha %d e coluna %d\n", maior, (guardaLinha+1), (guardaColuna+1));
    //OBS.: Se todos os elementos forem iguais, imprime o primeiro elemento
    //OBS.2: Se houver mais de um elemento com o maior valor, imprime o primeiro com o maior valor
    return 0;
}
