/*A UFRGS está organizando os “Jogos de Outono” com diversas atividades esportivas e decidiu
incluir uma nova modalidade para medir a pontaria dos esportistas. O jogo consiste em lançar uma
bola de metal o mais perto possível de uma linha marcada no começo do lançamento. Inicialmente
são 6 lançadores e cada um deles tem direito a 3 lançamentos. É importante saber que um
lançamento é válido tanto para lançamentos fortes demais quanto para lançamentos fracos demais;
por exemplo, se a linha estivesse a 1000 cm é válido tanto um lançamento a 980 cm quanto um a
1020 cm (em ambos os casos esteve a 20 cm do alvo, para menos ou para mais).
Para facilitar o preenchimento dos dados, vamos assumir que tanto a distância do alvo como
a matriz com todos os valores dos lançamentos dos jogadores serão gerados aleatoriamente pelo
programa com a função rand(), e estarão no intervalo entre 700 e 950 (inclusive) - lembre-se de
utilizar a função srand()!
Ao final, seu programa deve imprimir na tela a distância do alvo, a matriz de lançamentos,
quem foi o esportista com o melhor lançamento (em qualquer das tentativas) e a respectiva
distância do alvo, bem como o esportista com maior variação dentre as 3 tentativas realizadas
(maior diferença entre o lançamento mais longe e o lançamento mais próximo). Se houver empate
em qualquer quesito, imprima o valor do jogador de menor índice na matriz.
Observe o exemplo:
Alvo: 800
Lançamentos:
Tentativa \Jogador 1 2 3 4 5 6
Tentativa 1 700 780 812 855 710 900
Tentativa 2 900 770 816 813 759 860
Tentativa 3 750 740 820 820 723 857
Saída: O esportista 3 foi quem ganhou o jogo: 12 cm do alvo.
O esportista 1 foi quem teve maior variacao nos lancamentos: 200 cm.
Dica: revise na Aula 12 o uso da função rand() com inicialização manual da seed, para gerar
os números pseudo-aleatórios.*/

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

    //Como os vetores e matrizes precisam ser do mesmo tipo, não posso inserir texto ou caracteres nessa matriz de números inteiros.
    alvo = (MIN + (rand()%(MAX-MIN+1)));
    printf("Alvo: %d", alvo);
    printf("\nLancamentos:");
    //Atribui a cada espaço da matriz um número aleatório entre 750 e 900 (inclusives)
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

    //Verifica qual é a menor diferença (valor absoluto, função abs()) entre a distância lançada e o alvo:
    for (lin=0; lin<3; lin++){
        for (col=0; col<6; col++){
            if ((abs (alvo-(tabela[lin][col]))) < menorDistancia){
                menorDistancia = (abs (alvo-tabela[lin][col]));
                salvaGanhador = col+1;
            }
        }
    }
    printf("\nO esportista %d foi quem ganhou o jogo: %dcm do alvo.\n", salvaGanhador, menorDistancia);

    //Verifica qual jogador teve a maior variação entre os seus 3 lançamentos e qual foi essa diferença
    //Selection sort para ordenar os lançamentos de cada jogador em ordem crescente:

    for (col=0; col<6; col++){ //para cada coluna, percorre as linhas:
        //printf("\nvetor dos lancamentos do jogador %d em ordem crescente:\n", col+1);
        //inicializo o vetor menorMaior com os 3 valores da coluna na ordem em que aparecem:
        menorMaior[0] = tabela[0][col];
        menorMaior[1] = tabela[1][col];
        menorMaior[2] = tabela[2][col];
        for (i=0; i<2; i++){
            menor = i; //menor é a POSIÇÃO do menor
            for (j=(i+1); j<3; j++) {
                if (menorMaior[j] < menorMaior[menor]){ //troca a posição do menor elemento se necessário
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
