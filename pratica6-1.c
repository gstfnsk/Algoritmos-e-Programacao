/*Na criptografia de substituição, trocamos as ocorrências de
letras por outras de acordo com uma regra pré-definida,
usualmente baseada em um alfabeto de substituição. Uma
das formas de se gerar este alfabeto é utilizando um
deslocamento de passo fixo, como definido pela cifra ROT-13
(“Rotate by 13 places”), que é uma Cifra de César aplicável
aos caracteres alfabéticos e com passo 13, isto é, cada
caracter é rotacionado em 13 posições. Desta forma, o
caracter A vira N e vice versa, o caracter B vira O e
vice-versa, e assim por diante, finalizando com M virando Z e vice versa.

Faça um programa que leia uma string com um comprimento máximo de 40 caracteres e encontre a
string criptografada aplicando o alfabeto de substituição gerado pela cifra ROT-13. Considere que
as strings informadas irão conter apenas caracteres alfabéticos (letras) ou espaços em branco, e que
os espaços em branco não serão criptografados.Imprima na tela o resultado da string
criptografada.

Lembre-se que todos os caracteres alfabéticos possuem uma representação decimal de acordo com
a Tabela ASCII (veja ao final deste documento uma Tabela ASCII), a qual pode ser utilizada em
comparações, e que esta representação difere entre letras maiúsculas e minúsculas.
*/

#include<stdio.h>
#include<string.h>

int main (){
    char stringNormal[41], stringCriptografada[41]; //o usuário pode digitar até 40 caracteres, mas com o /0 fica 41
    int i, letra, tamanho;
    printf("Informe a String: ");
    //lê a string digitada:
    fgets(stringNormal, 40, stdin);
    //printf("\nString digitada: %s", stringNormal);

    tamanho = strnlen(stringNormal, 40);
    //printf("\nA string %s digitada tem comprimento %d", stringNormal, tamanho);

   while (stringNormal[i]!='\0'){ //copia o conteúdo da string normal pra string criptografada
        stringCriptografada[i] = stringNormal[i];
        i++;
    }
    stringCriptografada[i] = '\0';
    //printf("\nA string %s foi copiada para o vetor que sera criptografado \n", stringCriptografada);

    for (letra=0; letra<i; letra++){ // percorre o vetor
        if ((((stringCriptografada[letra]) >= 'A') && ((stringCriptografada[letra]) <= 'M')) || (((stringCriptografada[letra]) >= 'a') && ((stringCriptografada[letra]) <= 'm'))) { // se o caracter na posição [letra] estiver entre 'A' e 'M' ou 'a' e 'm':
                //printf("%c", stringCriptografada[letra]+13);
                stringCriptografada[letra] = stringCriptografada[letra]+13;
        }
        else if ((((stringCriptografada[letra]) >= 'N') && ((stringCriptografada[letra]) <= 'Z')) || (((stringCriptografada[letra]) >= 'n') && ((stringCriptografada[letra]) <= 'z'))) { // se o caracter na posição [letra] estiver entre 'N' e 'Z' ou 'n' e 'z':
                //printf("%c", stringCriptografada[letra]-13);
                stringCriptografada[letra] = stringCriptografada[letra]-13;
        }
    }
    printf("\nString criptografada: %s", stringCriptografada);

    return 0;
}
