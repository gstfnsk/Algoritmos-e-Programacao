/*Entrada
A entrada começa com um inteiro t, onde 1 ≤ t ≤ 1000, indicando o número de instâncias
(partidas) que seu programa deve analisar. Esta entrada deve ser validada.
Cada instância é composta por três linhas: na primeira a frase correta, na segunda a frase do
primeiro time e na terceira a frase do segundo time. Cada frase tem no máximo 100 caracteres, e
as frases garantidamente possuem sempre o mesmo tamanho.
Saída
Para cada instância, você deverá imprimir um identificador Instancia k, onde k é o número da
instância atual. Na linha seguinte você deve imprimir qual dos times foi o vencedor ou se houve
empate. Após cada instância, seu programa deve imprimir uma linha em branco.
*/

#include<stdio.h>
#include<string.h>

int main(){
    int t, i=0, indice, compara1=0, compara2=0;
    char stringOriginal[101], stringGrupo1[101], stringGrupo2[101];
    printf("Entre com um inteiro entre 1 (inclusive) e 1000 (inclusive): ");
    do{
            scanf("%d", &t);
            if ((t < 1) || (t>1000)){
                printf("\nValor invalido, digite um inteiro entre 1 (inclusive) e 1000 (inclusive): ");
            }
    }while ((t < 1) || (t>1000));
        //for (i=0; i<t; i++){ //esse for é para cada instância

    while (i<t){
        printf("\nInstancia %d\n", i+1); // imprime o número da instância
        printf("\nDigite a frase original: ");
        scanf(" %[^\n]s", stringOriginal);

        printf("\nDigite a frase do primeiro grupo: ");
        scanf(" %[^\n]s", stringGrupo1);

        printf("\nDigite a frase do segundo grupo: ");
        scanf(" %[^\n]s", stringGrupo2);

        //printf("\n \n A frase original digitada foi %s", stringOriginal);
        //printf("\n \n A frase do grupo 1 digitada foi %s", stringGrupo1);
        //printf("\n \n A frase do grupo 2 digitada foi %s", stringGrupo2);
        for (indice=0; indice<(strnlen (stringOriginal, 100)); indice++){ //esse for é para percorrer os vetores
            if ((stringGrupo1[indice]) == (stringOriginal[indice])){ //se os índices das strings 1 e original forem iguais:
                compara1++; //incrementa a variável "compara1"
            }
            if ((stringGrupo2[indice]) == (stringOriginal[indice])){ //e se os índices das strings 2 e original forem iguais:
                compara2++; //incrementa a variável "compara2"
            } //Obs. as duas condições são independentes entre si
        }
        if (compara1 > compara2){
            printf("\nO time 1 venceu a %d rodada\n\n", i+1);
        }
        else if (compara2 > compara1){
            printf("\nO time 2 venceu a %d rodada\n\n", i+1);
        }
        else if (compara1 == compara2){
            printf("\nempate\n\n");
        }
        i++;
    }
    return 0;
}
