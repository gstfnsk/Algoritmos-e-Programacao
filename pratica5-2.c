/*No programa de TV “Quem perde, ganha” o vencedor é o participante que perder mais peso durante
a competição. A produção do programa quer fazer o acompanhamento geral do peso dos
competidores e você será o responsável pelas estatísticas. Suponha que há 5 competidores nesta
edição. Sua tarefa é ler do teclado o peso dos 5 participantes, fazendo validação da entrada
(somente deverão ser aceitos valores maiores que 0), armazená-los em um vetor, e ao final da
leitura exibir na tela as seguintes estatísticas:
a) A média dos pesos, com 2 casas decimais.
b) O desvio padrão, com 2 casas decimais, dado pela fórmula:

Onde xi é o elemento atual (peso do competidor i), N é o número de elementos (5), µ é a média
calculada no item (a)
c) Quantos competidores têm o peso dentro da faixa de um desvio padrão da média, tanto para mais
quanto para menos. Isto é, quantos competidores satisfazem a condição: |xi – µ| < σ, onde xi é o
peso do competidor i*/

#include<stdio.h>
#include<math.h>

int main (){

    int i, contaCompetidores=0;
    float peso[5], media, somaPesos=0, desvioPadrao, pesoMenosMediaAoQuadrado=0, somatorio=0;

    for(i=0; i<5; i++){
        printf("\nDigite o peso %d: ", i+1);
        do{
            scanf("%f", &peso[i]);
            if (peso[i] <= 0){
                printf("Peso invalido, digite novamente\n");
            }
        }while (peso[i] <= 0);
        somaPesos += peso[i];
    }
    //cálculo da média dos pesos:
    media = somaPesos / i;
    printf("Media dos pesos: %.2f \n", media);

    for (i=0; i<5; i++){
        pesoMenosMediaAoQuadrado = ((peso[i] - media) * (peso[i] - media));
        somatorio += pesoMenosMediaAoQuadrado;
    }

    //1/4 = 0.25
    desvioPadrao = sqrt(0.25 * somatorio);
    printf("\nDesvio padrao: %.2f\n", desvioPadrao);

    for (i=0; i<5; i++){
        if ((fabs((peso[i])-media)) < desvioPadrao){
            contaCompetidores++;
        }
    }
    printf("\nNumero de participantes com peso dentro de 1 desvio padrao da media: %d\n", contaCompetidores);

    return 0;
}
