/*Fa�a um programa em C que leia do teclado 10 valores inteiros entre 0 e 20. Fa�a a valida��o da
entrada, garantindo que somente valores neste intervalo ser�o aceitos, isto �, que o programa ir�
repetir a leitura de um novo valor enquanto o usu�rio n�o digitar um valor v�lido.
Em seguida, o seu programa dever�:
a) Imprimir na tela todos os n�meros pares no vetor, ou, caso nenhum par tenha sido digitado,
imprimir "Nenhum valor par no vetor"
b) Ler do teclado um n�mero inteiro no mesmo intervalo (entre 0 e 20), realizando a
valida��o da entrada, e realizar a busca deste n�mero no vetor. Se o n�mero for encontrado
no vetor, o seu programa dever� imprimir quantas vezes ele foi encontrado e em que
posi��es do vetor. Caso contr�rio, se o n�mero n�o existir no vetor, seu programa dever�
imprimir "Numero X nao existe no vetor", onde X ser� substitu�do pelo valor digitado pelo
usu�rio.
*/
#include <stdio.h>
#include <math.h>
#define MAX 10

int main (){
    int i, valores[MAX], achou=0, busca, j=0, contaPosicoes[MAX], k=0;
    // l� e valida valores de 0 a 20 inseridos pelo usu�rio:
    for (i=0; i<MAX; i++){
        printf("Digite um valor entre 0 e 20: \n");
        do {
            scanf("%d", &valores[i]);
            if ((valores[i] > 20) || (valores[i] < 0)){
                printf("Valor invalido, digite novamente \n");
            }
        } while ((valores[i] > 20) || (valores[i] < 0));
    }
    //a)
    // imprime os valores pares encontrados, caso tenham sido encontrados:
    for (i=0; i<MAX; i++){
        if ((valores[i] % 2) == 0){
            achou = 1;
            printf("Valor par encontrado: %d \n", valores[i]);
        }
    }
   // se achou = 0, significa que nenhum valor foi encontrado:
    if (achou == 0){
        printf("\nNenhum valor par no vetor\n");
    }
    //b)
    printf("\nDigite o numero entre 0 e 20 que voce quer procurar no vetor: ");
    // verifica se o valor est� dentro do intervalo esperado:
    do {
        scanf("%d", &busca);
        if ((busca > 20) || (busca < 0)){
            printf("\nValor invalido, digite novamente: \n");
        }
    } while ((busca > 20) || (busca < 0));
    //k: �ndice do vetor contaPosicoes
    //j: vari�vel que conta quantas vezes o n�mero desejado "busca" foi encontrado no vetor
    for (i=0; i<MAX; i++){
        if (busca == valores[i]){
            contaPosicoes[k] = (i + 1);
            k++;
            j++;
        }
    }
    //se j for igual a 1, significa que 1 valor do vetor � igual ao n�mero desejado:
    if (j == 1){
        printf("\nO numero %d foi encontrado %d vez\n", busca, j);
        for(i=0; i<k; i++){
            printf("Numero encontrado no indice %d\n", contaPosicoes[i]);
        }
    }
    //se j for maior que 1, significa que o n�mero desejado foi encontrado mais de uma vez:
    if (j > 1){
        printf("\nO numero %d foi encontrado %d vezes\n", busca, j);
        for(i=0; i<k; i++){
            printf("Numero encontrado no indice %d\n", contaPosicoes[i]);
        }
    }
    //se j for igual a 0, j n�o incrementou nenhuma vez, o que significa que o n�mero n�o foi encontrado no vetor:
    if (j == 0){
        printf ("\nNumero %d nao existe no vetor\n", busca);
    }

    return 0;
}



