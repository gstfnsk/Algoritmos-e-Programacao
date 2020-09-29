/*Na criptografia de substitui��o, trocamos as ocorr�ncias de
letras por outras de acordo com uma regra pr�-definida,
usualmente baseada em um alfabeto de substitui��o. Uma
das formas de se gerar este alfabeto � utilizando um
deslocamento de passo fixo, como definido pela cifra ROT-13
(�Rotate by 13 places�), que � uma Cifra de C�sar aplic�vel
aos caracteres alfab�ticos e com passo 13, isto �, cada
caracter � rotacionado em 13 posi��es. Desta forma, o
caracter A vira N e vice versa, o caracter B vira O e
vice-versa, e assim por diante, finalizando com M virando Z e vice versa.

Fa�a um programa que leia uma string com um comprimento m�ximo de 40 caracteres e encontre a
string criptografada aplicando o alfabeto de substitui��o gerado pela cifra ROT-13. Considere que
as strings informadas ir�o conter apenas caracteres alfab�ticos (letras) ou espa�os em branco, e que
os espa�os em branco n�o ser�o criptografados.Imprima na tela o resultado da string
criptografada.

Lembre-se que todos os caracteres alfab�ticos possuem uma representa��o decimal de acordo com
a Tabela ASCII (veja ao final deste documento uma Tabela ASCII), a qual pode ser utilizada em
compara��es, e que esta representa��o difere entre letras mai�sculas e min�sculas.
*/

#include<stdio.h>
#include<string.h>

int main (){
    char stringNormal[41], stringCriptografada[41]; //o usu�rio pode digitar at� 40 caracteres, mas com o /0 fica 41
    int i, letra, tamanho;
    printf("Informe a String: ");
    //l� a string digitada:
    fgets(stringNormal, 40, stdin);
    //printf("\nString digitada: %s", stringNormal);

    tamanho = strnlen(stringNormal, 40);
    //printf("\nA string %s digitada tem comprimento %d", stringNormal, tamanho);

   while (stringNormal[i]!='\0'){ //copia o conte�do da string normal pra string criptografada
        stringCriptografada[i] = stringNormal[i];
        i++;
    }
    stringCriptografada[i] = '\0';
    //printf("\nA string %s foi copiada para o vetor que sera criptografado \n", stringCriptografada);

    for (letra=0; letra<i; letra++){ // percorre o vetor
        if ((((stringCriptografada[letra]) >= 'A') && ((stringCriptografada[letra]) <= 'M')) || (((stringCriptografada[letra]) >= 'a') && ((stringCriptografada[letra]) <= 'm'))) { // se o caracter na posi��o [letra] estiver entre 'A' e 'M' ou 'a' e 'm':
                //printf("%c", stringCriptografada[letra]+13);
                stringCriptografada[letra] = stringCriptografada[letra]+13;
        }
        else if ((((stringCriptografada[letra]) >= 'N') && ((stringCriptografada[letra]) <= 'Z')) || (((stringCriptografada[letra]) >= 'n') && ((stringCriptografada[letra]) <= 'z'))) { // se o caracter na posi��o [letra] estiver entre 'N' e 'Z' ou 'n' e 'z':
                //printf("%c", stringCriptografada[letra]-13);
                stringCriptografada[letra] = stringCriptografada[letra]-13;
        }
    }
    printf("\nString criptografada: %s", stringCriptografada);

    return 0;
}
