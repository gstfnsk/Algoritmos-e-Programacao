/*Flíper é um tipo de jogo onde uma bolinha de metal cai por um labirinto de caminhos até chegar na parte
de baixo do labirinto. A quantidade de pontos que o jogador ganha depende do caminho que a bolinha
seguir. O jogador pode controlar o percurso da bolinha mudando a posição de algumas portinhas do
labirinto. Cada portinha pode estar na posição 0, que significa virada para a esquerda, ou na posição 1
que quer dizer virada para a direita. Considere o flíper da figura abaixo, que tem duas portinhas: a
portinha P está na posição 1 e a portinha R, na posição 0. Desse jeito, a bolinha vai cair pelo caminho B.

Você deve escrever um programa que dado um crédito inicial em reais informado pelo usuário (valor >
0, faça validação da entrada), permita ao jogador realizar múltiplas jogadas enquanto for possível, isto é,
enquanto houver crédito suficiente para comprar uma ficha do flíper. Cada ficha tem um custo de
R$2,75. A cada nova partida o jogador deve informar as posições das portinhas P e R através do teclado,
como no flíper da figura. Apenas valores iguais a 0 ou 1 devem ser aceitos como entradas para P e R, e
seu programa deve repetir a leitura enquanto o valor digitado for inválido. Com base nas posições lidas
para as portinhas, o seu programa deverá informar por qual dos três caminhos, A, B ou C, a bolinha vai
cair, bem como a quantidade de pontos conquistados na partida. Considere que o caminho A vale 10
pontos, B vale 15 pontos e C vale 05 pontos. Quando o jogador não tiver mais créditos suficientes para
jogar nova partida, o seu programa deverá informar o total de pontos acumulados em todas as partidas
do jogador antes do programa encerrar.
*/

#include<stdio.h>
#include<math.h>
#define FICHA 2.75

int main (){

    float credito, pontos = 0;
    int P, R;

    do {
        printf("\nDigite o valor de credito inicial: ");
        scanf("%f", &credito);
        if (credito <= 0){
            printf("\nO valor deve ser maior que zero\n");
        }
    } while (credito <=0);

    while (credito >= 2.75){
            do {
                printf("\nDigite 0 ou 1 para a porta P e 0 ou 1 para a porta R: ");
                scanf("%d %d", &P, &R);
                credito -= FICHA;
                if (((P != 0) && (P !=1)) || ((R != 0) && (R != 1))){
                    printf("Valor invalido \n");
                }
                if (P == 0){
                    printf("\nCaminho C! +05 pontos \nCredito restante:  %.2f \n", credito);
                    pontos += 5;
                }
                else if (P == 1){
                    if (R == 1){
                        printf("\nCaminho A! +10 pontos \nCredito restante: %.2f \n", credito);
                        pontos += 10;
                    }
                    else if (R == 0){
                        printf("\nCaminho B! +15 pontos \nCredito restante: %.2f \n", credito);
                        pontos += 15;
                    }
                }
            } while (((P != 0) && (P !=1)) || ((R != 0) && (R != 1)));
    }
    printf("\n Creditos finalizados ou insuficientes! \n");
    printf("Total de pontos acumulados pelo jogador: %.2f \n", pontos);

    return 0;
}
