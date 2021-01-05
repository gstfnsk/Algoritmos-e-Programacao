/*INF01202 - ALGORITMOS E PROGRAMAÇÃO - TURMAS A/B
Profa. Mariana Recamonde Mendoza
2020/01
Aula Prática 10
Elabore um programa em C para o(s) problema(s) a seguir. A entrega dos exercícios deve
ser feita através do link disponibilizado no Moodle, no prazo lá indicado. Envie o arquivo .c.
PROBLEMA 1:
Considere a estrutura abaixo, já codificada em C, que armazena os dados de um jogador do Lolo's
Adventure ao longo do jogo. A estrutura possui um campo para guardar i) total de pontos já
acumulados, ii) fase atual do jogo; iii) número de vidas e iv) nome do jogador (sugere-se usar o
tamanho indicado, entretanto, alunos podem optar por implementar uma string mais longa).
struct jogador_st {
int totalpts;
int fase;
int vidas;
char nomejogador[9];
};
No funcionamento real do jogo, esta estrutura será atualizada conforme a dinâmica do jogo. Neste
exercício, vamos simplificar este aspecto, preenchendo os dados a partir do teclado.

1.1 Faça uma função que leia do teclado os dados que compõem a estrutura, armazene os dados nos
respectivos campos, e retorne à função chamadora a estrutura preenchida. O retorno pode ser feito
tanto por meio do return, como através do uso de passagem de parâmetros por referência, à critério
do aluno
1.2 Faça uma função que receba como entrada uma variável do tipo struct jogador_st, e imprima
na tela os valores dos campos desta estrutura, com formatação adequada. Por exemplo:
Jogador: Fulano
Vidas: 3
Total de pontos: 7
Fase: 2
1.3 Na main:
- Declare uma variável do tipo struct jogador_st (se desejar, faça uso do
typedef para criar um sinônimo mais curto para este tipo de dado)
- Inicialize esta variável; através da função criada no item 1.1.
- Imprima na tela os dados do jogador através da função criada no item 1.2.*/
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
    dados = leEstrutura(); //questão 1
    imprimeEstrutura(dados); //questão 1
    printf("\n\n\n");
    //questão 2:
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
(Atenção: este problema pode ser entregue no mesmo arquivo .c do exercício anterior, por se tratar
de uma extensão do mesmo.)
2.1 Faça uma função que receba como entrada um vetor de struct jogador_st com comprimento
length (inteiro), ambos informados como parâmetros para a função, e retorne o índice do jogador
com maior pontuação dentre todos no vetor.
2.2 Na main, adapte seu programa para :
- Declarar um vetor do tipo struct jogador_st com tamanho 5
- Preencher os dados deste vetor com a função criada no Exercício 1
- Imprimir na tela os dados de todos os jogadores, utilizando a função criada no Exercício 1
- Imprimir na tela a mensagem "Jogador com maior pontuação", seguida pelos dados do
jogador que obteve a maior pontuação dentre todos os 5 jogadores. Este jogador deve ser
encontrado através do uso da função implementada no item 2.1.*/

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
