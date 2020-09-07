/*Fl�per � um tipo de jogo onde uma bolinha de metal cai por um labirinto de caminhos at� chegar na parte
de baixo do labirinto. A quantidade de pontos que o jogador ganha depende do caminho que a bolinha
seguir. O jogador pode controlar o percurso da bolinha mudando a posi��o de algumas portinhas do
labirinto. Cada portinha pode estar na posi��o 0, que significa virada para a esquerda, ou na posi��o 1
que quer dizer virada para a direita. Considere o fl�per da figura abaixo, que tem duas portinhas: a
portinha P est� na posi��o 1 e a portinha R, na posi��o 0. Desse jeito, a bolinha vai cair pelo caminho B.

Voc� deve escrever um programa que dado um cr�dito inicial em reais informado pelo usu�rio (valor >
0, fa�a valida��o da entrada), permita ao jogador realizar m�ltiplas jogadas enquanto for poss�vel, isto �,
enquanto houver cr�dito suficiente para comprar uma ficha do fl�per. Cada ficha tem um custo de
R$2,75. A cada nova partida o jogador deve informar as posi��es das portinhas P e R atrav�s do teclado,
como no fl�per da figura. Apenas valores iguais a 0 ou 1 devem ser aceitos como entradas para P e R, e
seu programa deve repetir a leitura enquanto o valor digitado for inv�lido. Com base nas posi��es lidas
para as portinhas, o seu programa dever� informar por qual dos tr�s caminhos, A, B ou C, a bolinha vai
cair, bem como a quantidade de pontos conquistados na partida. Considere que o caminho A vale 10
pontos, B vale 15 pontos e C vale 05 pontos. Quando o jogador n�o tiver mais cr�ditos suficientes para
jogar nova partida, o seu programa dever� informar o total de pontos acumulados em todas as partidas
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
