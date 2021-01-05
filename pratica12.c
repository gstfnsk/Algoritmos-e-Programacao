#include<stdio.h>
#include<string.h>
#define TAMLINHA 20

int main(){
    FILE *arq;
    FILE *arqFumantes;
    FILE *arqNaoFumantes;
    FILE *estatisticas;
    char linha[TAMLINHA];
    int contaLinhas=0, contaFumantes=0, contaHomens=0, contaHomensNaoFumantesAbaixo40=0, contaMulheres=0, contaMulheresNaoFumantesAbaixo40=0;
    if(!(arq=fopen("dados.txt", "r")) )
        printf("Erro ao abrir arquivo!\n");
    else{
        while(!feof(arq)) {
            if ((fgets(linha, TAMLINHA, arq) != NULL))
                //printf("%s\n", linha); //imprime conteúdo do arquivo (linhas, fgets)
                contaLinhas++;
                if(linha[0]=='F'){
                    contaMulheres++;
                }
                if(linha[0]=='M'){
                    contaHomens++;
                }
        }
        rewind(arq);
        //separar em 2 arquivos: fumantes.txt e naofumantes.txt, igual ao original
        if ((arqFumantes = fopen("fumantes.txt", "w")) == NULL)
            printf("Erro ao abrir arquivo fumantes \n");
        else{
            while (!feof(arq)){ //percorre arquivo original
                if((fgets(linha, sizeof(linha), arq)!= NULL)&& (linha[5] == 'S')){ //se leu linha e o quinto caractere da string é S
                    //printf("%s\n", linha);
                    contaFumantes++;
                    fputs (linha, arqFumantes); //grava linha
                }
            }
            //printf("\nNumero de fumantes: %d\n", contaFumantes);
        }
        rewind(arq);
        if ((arqNaoFumantes = fopen("naofumantes.txt", "w")) == NULL)
            printf("Erro ao abrir arquivo de nao fumantes \n");
        else{
            while (!feof(arq)){ //percorre arquivo original
                if((fgets(linha, sizeof(linha), arq)!= NULL)&& (linha[5] == 'N')){ //se leu linha e o quinto caractere da string é N
                    //printf("%s\n", linha);
                    fputs (linha, arqNaoFumantes); //grava linha
                    if ((linha[0]=='F')&& (linha[2]<'4')){
                        contaMulheresNaoFumantesAbaixo40++;
                    }
                    if ((linha[0]=='M')&& (linha[2]<'4')){
                        contaHomensNaoFumantesAbaixo40++;
                    }
                }
            }
        }
        rewind(arq);
        //outro arquivo com as estatísticas:
        /* -Qual é o número total de entrevistados?
           -Qual é o percentual de fumantes em relação ao número total de pessoas
            entrevistadas?
           -Qual é o percentual de homens não fumantes abaixo de 40 anos em relação ao
            número total de homens entrevistados?
           -Qual é o percentual de mulheres não fumantes abaixo de 40 anos em relação ao
            número total de mulheres entrevistadas?
        */
        if(!(estatisticas=fopen("estatisticas.txt", "w")))
            printf("Erro ao abrir arquivo!\n");
        else{
            //printf("Numero total de entrevistados: %d\n", contaLinhas);
            fprintf(estatisticas, "Numero total de entrevistados: %d\n", contaLinhas);
            //printf("Percentual de fumantes em relacao ao numero total de pessoas: %.2f\n", (float) contaFumantes*100/contaLinhas);
            fprintf(estatisticas, "Percentual de fumantes em relacao ao numero total de pessoas: %.2f\n", (float) contaFumantes*100/contaLinhas);
            //printf("Percentual de homens nao fumantes abaixo de 40 anos em relacao ao numero total de homens entrevistados: %.2f%%\n", (float) contaHomensNaoFumantesAbaixo40*100/contaHomens);
            fprintf(estatisticas, "Percentual de homens nao fumantes abaixo de 40 anos em relacao ao numero total de homens entrevistados: %.2f%%\n", (float) contaHomensNaoFumantesAbaixo40*100/contaHomens);
            //printf("Percentual de mulheres nao fumantes abaixo de 40 anos em relacao ao numero total de mulheres entrevistadas: %.2f%%\n", (float) contaMulheresNaoFumantesAbaixo40*100/contaMulheres);
            fprintf(estatisticas, "Percentual de mulheres nao fumantes abaixo de 40 anos em relacao ao numero total de mulheres entrevistadas: %.2f%%\n", (float) contaMulheresNaoFumantesAbaixo40*100/contaMulheres);
            }
    }
    fclose(arq);
    fclose(arqFumantes);
    fclose(arqNaoFumantes);
    fclose(estatisticas);
    return 0;
}
