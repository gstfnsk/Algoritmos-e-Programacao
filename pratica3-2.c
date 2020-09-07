/* A taxa de natalidade e taxa de mortalidade são indicadores de desenvolvimento humano
importantes que permitem analisar a dinâmica de uma população, demonstrando seu crescimento
ou declínio.
A taxa de natalidade refere-se ao cálculo que indica o número de nascidos vivos ao longo de um ano
a cada mil habitantes. O seu cálculo pode ser expresso como:
taxa de natalidade = (número de nascimentos x 1000) / número de habitantes
A taxa de mortalidade, por outro lado, indica o número de óbitos ao longo de um ano a cada mil
habitantes, sendo calculada como:
taxa de mortalidade = (números de óbitos x 1000) /número de habitantes
Ambas são expressas em termos de porcentagem.
Faça um programa em C que possibilite o cálculo destes indicadores, utilizando o comando
switch. O seu programa deverá apresentar ao usuário as duas opções de indicadores e solicitar que
digite 'M' ou 'm' para cálculo da taxa de mortalidade, e 'N' ou 'n' para a taxa de natalidade. Todos os
dados necessário para cálculo das taxas serão informados pelo usuário. Após leitura da opção e dos
dados necessários para cálculo, realize o cálculo da taxa escolhida e imprima na tela o resultado
com duas casas decimais.
*/

#include<stdio.h>
#include<math.h>

int main (){

    int obitosOuNascimentos, habitantes;
    float calculo;
    char indicador;

    printf("Digite 'M' se voce quer saber a taxa de mortalidade e 'N' se quer saber a taxa de natalidade: ");
    scanf("%c", &indicador);
    printf("Digite o numero de obitos caso tenha digitado 'M' ou numero de nascimentos caso tenha digitado 'N': ");
    scanf("%d", &obitosOuNascimentos);
    printf("Digite o numero total de habitantes da cidade: ");
    scanf("%d", &habitantes);

    calculo = (obitosOuNascimentos * 1000.0) / habitantes;

    switch (indicador){
        case 'M': printf("Taxa de mortalidade: %.2f%%  \n", calculo);
            break;
        case 'm': printf("Taxa de mortalidade: %.2f%% \n", calculo);
            break;
        case 'N': printf("Taxa de natalidade: %.2f%% \n", calculo);
            break;
        case 'n': printf("Taxa de natalidade: %.2f%% \n", calculo);
            break;
    }
    return 0;
}
