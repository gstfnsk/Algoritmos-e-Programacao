
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define TAM 150

void contaVogaisEConsoantes(char* frase, int tam, int* vogais, int* consoantes){
    int i, contaVogais=0, contaConsoantes=0;
    for (i=0; i<tam; i++){
        *(frase+i) = toupper(*(frase+i));
        if ((*(frase+i)>='A')&&(*(frase+i)<='Z')){
            if ((*(frase+i)=='A') || (*(frase+i)=='E') || (*(frase+i)=='I') || (*(frase+i)=='O') || (*(frase+i)=='U')){
                contaVogais++;
            }
            else {
                contaConsoantes++;
            }
        }
    }
    *vogais=contaVogais;
    *consoantes=contaConsoantes;
    //printf("\nA frase digitada foi: %s", frase);
}

int main(){
    char frase[TAM+1];
    int qtdVogais, qtdConsoantes, i, num;
    printf("Digite uma frase de no maximo 150 caracteres e sem acentuacao: ");
    scanf("%[^\n]", frase);
    num = strnlen(frase, TAM+1);
    contaVogaisEConsoantes(frase, num, &qtdVogais, &qtdConsoantes);
    printf ("\nVogais: %d \nConsoantes: %d\n", qtdVogais, qtdConsoantes);

    return 0;
}
