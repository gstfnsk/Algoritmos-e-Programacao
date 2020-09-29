/*A UFRGS est� organizando os �Jogos de Outono� com diversas atividades esportivas e decidiu
incluir uma nova modalidade para medir a pontaria dos esportistas. O jogo consiste em lan�ar uma
bola de metal o mais perto poss�vel de uma linha marcada no come�o do lan�amento. Inicialmente
s�o 6 lan�adores e cada um deles tem direito a 3 lan�amentos. � importante saber que um
lan�amento � v�lido tanto para lan�amentos fortes demais quanto para lan�amentos fracos demais;
por exemplo, se a linha estivesse a 1000 cm � v�lido tanto um lan�amento a 980 cm quanto um a
1020 cm (em ambos os casos esteve a 20 cm do alvo, para menos ou para mais).
Para facilitar o preenchimento dos dados, vamos assumir que tanto a dist�ncia do alvo como
a matriz com todos os valores dos lan�amentos dos jogadores ser�o gerados aleatoriamente pelo
programa com a fun��o rand(), e estar�o no intervalo entre 700 e 950 (inclusive) - lembre-se de
utilizar a fun��o srand()!
Ao final, seu programa deve imprimir na tela a dist�ncia do alvo, a matriz de lan�amentos,
quem foi o esportista com o melhor lan�amento (em qualquer das tentativas) e a respectiva
dist�ncia do alvo, bem como o esportista com maior varia��o dentre as 3 tentativas realizadas
(maior diferen�a entre o lan�amento mais longe e o lan�amento mais pr�ximo). Se houver empate
em qualquer quesito, imprima o valor do jogador de menor �ndice na matriz.
Observe o exemplo:
Alvo: 800
Lan�amentos:
Tentativa \Jogador 1 2 3 4 5 6
Tentativa 1 700 780 812 855 710 900
Tentativa 2 900 770 816 813 759 860
Tentativa 3 750 740 820 820 723 857
Sa�da: O esportista 3 foi quem ganhou o jogo: 12 cm do alvo.
O esportista 1 foi quem teve maior variacao nos lancamentos: 200 cm.
Dica: revise na Aula 12 o uso da fun��o rand() com inicializa��o manual da seed, para gerar
os n�meros pseudo-aleat�rios.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#define MAX 950
#define MIN 700

int main (){
    srand(time(NULL));
    int col, lin, alvo, menorDistancia=INT_MAX, salvaGanhador, salvaJogador, menorMaior[3], i, j, aux, menor, diferenca, maiorDiferenca=INT_MIN;
    int tabela[3][6];

    //Como os vetores e matrizes precisam ser do mesmo tipo, n�o posso inserir texto ou caracteres nessa matriz de n�meros inteiros.
    alvo = (MIN + (rand()%(MAX-MIN+1)));
    printf("Alvo: %d", alvo);
    printf("\nLancamentos:");
    //Atribui a cada espa�o da matriz um n�mero aleat�rio entre 750 e 900 (inclusives)
    for (col=0; col<6; col++){
        for (lin=0; lin<3; lin++){
            tabela[lin][col] = (MIN + (rand()%(MAX-MIN+1)));
        }
    }
    //imprime a tabela gerada:
    printf("\nTentativa|Jogador  1 \t\t   2 \t\t   3 \t\t   4 \t\t   5 \t\t   6\n");
    for (lin=0; lin<3; lin++){
        for (col=0; col<6; col++){
                if (col == 0){
                    printf("\n    T%d", lin+1);
                }
            printf("\t\t%5d", tabela[lin][col]);
        }
        printf("\n");
    }

    //Verifica qual � a menor diferen�a (valor absoluto, fun��o abs()) entre a dist�ncia lan�ada e o alvo:
    for (lin=0; lin<3; lin++){
        for (col=0; col<6; col++){
            if ((abs (alvo-(tabela[lin][col]))) < menorDistancia){
                menorDistancia = (abs (alvo-tabela[lin][col]));
                salvaGanhador = col+1;
            }
        }
    }
    printf("\nO esportista %d foi quem ganhou o jogo: %dcm do alvo.\n", salvaGanhador, menorDistancia);

    //Verifica qual jogador teve a maior varia��o entre os seus 3 lan�amentos e qual foi essa diferen�a
    //Selection sort para ordenar os lan�amentos de cada jogador em ordem crescente:

    for (col=0; col<6; col++){ //para cada coluna, percorre as linhas:
        //printf("\nvetor dos lancamentos do jogador %d em ordem crescente:\n", col+1);
        //inicializo o vetor menorMaior com os 3 valores da coluna na ordem em que aparecem:
        menorMaior[0] = tabela[0][col];
        menorMaior[1] = tabela[1][col];
        menorMaior[2] = tabela[2][col];
        for (i=0; i<2; i++){
            menor = i; //menor � a POSI��O do menor
            for (j=(i+1); j<3; j++) {
                if (menorMaior[j] < menorMaior[menor]){ //troca a posi��o do menor elemento se necess�rio
                    menor = j;
                }
            }
            if (i != menor) {
                aux = menorMaior[i];
                menorMaior[i] = menorMaior[menor];
                menorMaior[menor] = aux;
            }
        }
        for (i=0; i<3; i++){
            //printf("\t %d ", menorMaior[i]);
        }
        diferenca = menorMaior[2] - menorMaior[0];
        //printf("\n\na diferenca entre o maior e o menor lancamento do jogador %d foi %d\n", col+1, diferenca);
        if (diferenca > maiorDiferenca){
            maiorDiferenca = diferenca;
            salvaJogador = col+1;
        }
    }
    printf("\nO esportista %d foi quem teve maior variacao nos lancamentos: %dcm.\n", salvaJogador, maiorDiferenca);

    return 0;
}
