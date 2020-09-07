/* A taxa de natalidade e taxa de mortalidade s�o indicadores de desenvolvimento humano
importantes que permitem analisar a din�mica de uma popula��o, demonstrando seu crescimento
ou decl�nio.
A taxa de natalidade refere-se ao c�lculo que indica o n�mero de nascidos vivos ao longo de um ano
a cada mil habitantes. O seu c�lculo pode ser expresso como:
taxa de natalidade = (n�mero de nascimentos x 1000) / n�mero de habitantes
A taxa de mortalidade, por outro lado, indica o n�mero de �bitos ao longo de um ano a cada mil
habitantes, sendo calculada como:
taxa de mortalidade = (n�meros de �bitos x 1000) /n�mero de habitantes
Ambas s�o expressas em termos de porcentagem.
Fa�a um programa em C que possibilite o c�lculo destes indicadores, utilizando o comando
switch. O seu programa dever� apresentar ao usu�rio as duas op��es de indicadores e solicitar que
digite 'M' ou 'm' para c�lculo da taxa de mortalidade, e 'N' ou 'n' para a taxa de natalidade. Todos os
dados necess�rio para c�lculo das taxas ser�o informados pelo usu�rio. Ap�s leitura da op��o e dos
dados necess�rios para c�lculo, realize o c�lculo da taxa escolhida e imprima na tela o resultado
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
