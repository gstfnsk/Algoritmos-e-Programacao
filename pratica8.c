/*A. Crie uma fun��o que imprima na tela o menu inicial do jogo apresentando ao usu�rio as
seguintes op��es:
(N) - Novo Jogo
(C) - Carregar Jogo
(M) - Mostrar Cr�ditos
(S) - Sair*/

/*B. Crie uma fun��o que fa�a a leitura e valida��o de uma entrada do usu�rio para sele��o da
op��o do menu. Esta fun��o deve aceitar como entrada somente os caracteres �N�, �C�, �M� ou
�S� como entrada, portanto, a leitura deve ser repetida at� que o usu�rio digite uma
informa��o v�lida. Quando uma entrada v�lida for informada, a fun��o deve retornar esta
informa��o. Sempre que uma entrada for inv�lida, ela deve imprimir na tela �Opcao
invalida� e em seguida mostrar novamente o menu com op��es dispon�veis.
Dica: Voc� pode utilizar a fun��o toupper() da biblioteca ctype.h, que recebe um caracter em
min�sculo e transforma o mesmo para mai�sculo. Assim, voc� permite que o usu�rio digite
�n� para a op��o novo Jogo sem ter que explicitamente tratar estas duas entradas. Exemplo
de uso:
char op;
op = toupper(op);*/

/*C. Crie uma fun��o que receba como entrada uma op��o digitada pelo usu�rio (j� validada), e
trate esta op��o (de forma simplificada), da seguinte forma:
a. Se a op��o for �N� (novo jogo), leia o nome do jogador (com at� 10 caracteres) e
imprima na tela a mensagem �Jogador XXXXXXXXXX: se prepare, jogo iniciando!!�,
onde �XXXXXXXXXX� ser� substitu�do pelo nome digitado.
b. Se a op��o for �C� (carregar jogo), o programa deve imprimir na tela a mensagem
�Carregando a lista de jogos salvos, aguarde um minuto.�
c. Se a op��o for �M� (mostrar cr�ditos), o programa deve imprimir na tela os cr�ditos
para os desenvolvedores do c�digo, isto �, seu nome e cartao UFRGS.
d. Se a op��o for �S� (sair), o programa deve imprimir na tela a mensagem �Encerrando
o jogo, ateh a proxima!� .
*/

/*D. Crie a fun��o main, obrigat�ria em todo programa C. A fun��o main deve iniciar
imprimindo na tela o nome do jogo Lolo�s Adventure. Ela ser� a respons�vel por organizar a
din�mica da aplica��o, chamando as fun��es auxiliares para fazer as tarefas de impress�o
de menu, leitura e valida��o de entrada, e tratamento de entrada. Seu funcionamento deve
permitir que o programa fique em execu��o at� que o usu�rio digite �S� para sair. Desta
forma, ap�s mostrar o menu e ler e tratar a entrada do usu�rio, se a entrada for diferente de
�S� ele deve repetir estes passos. O programa termina quando o usu�rio seleciona a op��o de
sair.*/

#include<stdio.h>
#include<ctype.h>

char menu (){
    printf("\n****** MENU ****** \n(N) - Novo Jogo \n(C) - Carregar Jogo \n(M) - Mostrar Creditos \n(S) - Sair \n");
}

char validaLeitura(){
    char opcao;
    do {
        scanf(" %c", &opcao);
        opcao = toupper(opcao);
        //printf("caractere digitado: %c", opcao);
        if ((opcao != 'N')&&(opcao != 'C')&&(opcao != 'M')&&(opcao != 'S')){
            printf("\nOpcao invalida\n");
            menu();
        }
    } while ((opcao != 'N')&&(opcao != 'C')&&(opcao != 'M')&&(opcao != 'S'));
    return opcao;
}

//o tipo da fun��o � o tipo do que ela retorna, no caso n�o retorna nada

void funcao(char opcao){
    char nome[11];
    if (opcao == 'N'){
        printf("\nDigite o nome do jogador:\n");
        scanf("%s", nome);
        printf("\nJogador %s: se prepare, jogo iniciando!!\n\n", nome);
    }
    if (opcao == 'C'){
        printf("\nCarregando a lista de jogos salvos, aguarde um minuto.\n\n");
    }
    if (opcao == 'M'){
        printf("\nCreditos: Giulia 00289108\n\n");
    }
    if (opcao == 'S'){
        printf("\nEncerrando o jogo, ateh a proxima!\n\n");
    }
}

int main(){
    char op;
    do{
        printf("Lolo's Adventure\n");
        menu();
        op = validaLeitura();
        funcao(op);
    } while (op != 'S');

    return 0;
}

