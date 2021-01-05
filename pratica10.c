/*INF01202 - ALGORITMOS E PROGRAMA��O - TURMAS A/B
Profa. Mariana Recamonde Mendoza
2020/01
Aula Pr�tica 10
Elabore um programa em C para o(s) problema(s) a seguir. A entrega dos exerc�cios deve
ser feita atrav�s do link disponibilizado no Moodle, no prazo l� indicado. Envie o arquivo .c.
PROBLEMA 1:
Considere a estrutura abaixo, j� codificada em C, que armazena os dados de um jogador do Lolo's
Adventure ao longo do jogo. A estrutura possui um campo para guardar i) total de pontos j�
acumulados, ii) fase atual do jogo; iii) n�mero de vidas e iv) nome do jogador (sugere-se usar o
tamanho indicado, entretanto, alunos podem optar por implementar uma string mais longa).
struct jogador_st {
int totalpts;
int fase;
int vidas;
char nomejogador[9];
};
No funcionamento real do jogo, esta estrutura ser� atualizada conforme a din�mica do jogo. Neste
exerc�cio, vamos simplificar este aspecto, preenchendo os dados a partir do teclado.

1.1 Fa�a uma fun��o que leia do teclado os dados que comp�em a estrutura, armazene os dados nos
respectivos campos, e retorne � fun��o chamadora a estrutura preenchida. O retorno pode ser feito
tanto por meio do return, como atrav�s do uso de passagem de par�metros por refer�ncia, � crit�rio
do aluno
1.2 Fa�a uma fun��o que receba como entrada uma vari�vel do tipo struct jogador_st, e imprima
na tela os valores dos campos desta estrutura, com formata��o adequada. Por exemplo:
Jogador: Fulano
Vidas: 3
Total de pontos: 7
Fase: 2
1.3 Na main:
- Declare uma vari�vel do tipo struct jogador_st (se desejar, fa�a uso do
typedef para criar um sin�nimo mais curto para este tipo de dado)
- Inicialize esta vari�vel; atrav�s da fun��o criada no item 1.1.
- Imprima na tela os dados do jogador atrav�s da fun��o criada no item 1.2.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<limits.h>
#define NOME 9
#define NJOGADORES 5

typedef struct jogador_st {
int totalPontos;
int fase;
int vidas;
char nomeJogador[NOME];
}dados_st;

//1.1
dados_st leEstrutura(){
    dados_st dados;
    int i;
    printf("\nDigite o total de pontos: ");
    scanf("%d", &dados.totalPontos);
    printf("\nDigite a fase: ");
    scanf("%d", &dados.fase);
    printf("\nDigite o numero de vidas: ");
    scanf("%d", &dados.vidas);
    printf("\nDigite o nome do/a jogador/a: ");
    scanf("%s", dados.nomeJogador);
    return dados;
}

//1.2
void imprimeEstrutura(dados_st dados){
    printf("Jogador(a): %s\n", dados.nomeJogador);
    printf("Vidas: %d\n", dados.vidas);
    printf("Total de pontos: %d\n", dados.totalPontos);
    printf("Fase: %d\n", dados.fase);
}

//prototipo da 2.1:
int maiorPontuacao (dados_st*, int);

//1.3
int main(){
    dados_st dados, listaJogadores[NJOGADORES];
    int i, ind;
    dados = leEstrutura(); //quest�o 1
    imprimeEstrutura(dados); //quest�o 1
    printf("\n\n\n");
    //quest�o 2:
    for (i=0; i<NJOGADORES; i++){
        listaJogadores[i] = leEstrutura();
    }
    for (i=0; i<NJOGADORES; i++){
        imprimeEstrutura(listaJogadores[i]);
    }
    ind = maiorPontuacao(listaJogadores, NJOGADORES);
    //printf("\n\nmaior na main: %d\n\n", ind);
    printf("\nJogador com maior pontuacao: \n");
    imprimeEstrutura(listaJogadores[ind]);
    return 0;
}
/*
PROBLEMA 2:
(Aten��o: este problema pode ser entregue no mesmo arquivo .c do exerc�cio anterior, por se tratar
de uma extens�o do mesmo.)
2.1 Fa�a uma fun��o que receba como entrada um vetor de struct jogador_st com comprimento
length (inteiro), ambos informados como par�metros para a fun��o, e retorne o �ndice do jogador
com maior pontua��o dentre todos no vetor.
2.2 Na main, adapte seu programa para :
- Declarar um vetor do tipo struct jogador_st com tamanho 5
- Preencher os dados deste vetor com a fun��o criada no Exerc�cio 1
- Imprimir na tela os dados de todos os jogadores, utilizando a fun��o criada no Exerc�cio 1
- Imprimir na tela a mensagem "Jogador com maior pontua��o", seguida pelos dados do
jogador que obteve a maior pontua��o dentre todos os 5 jogadores. Este jogador deve ser
encontrado atrav�s do uso da fun��o implementada no item 2.1.*/

//2.1
int maiorPontuacao (dados_st* dados, int comprimento){
    int i, maior=INT_MIN, indice=0;
    for (i=0; i<comprimento; i++){
        if((dados[i].totalPontos) > maior){
            maior = (dados[i].totalPontos);
            //printf("\n\nmaior: %d\n\n", maior);
            indice = i;
        }
    }
    //printf("\n\nindice = %d\n\n", indice);
    return indice;
}
