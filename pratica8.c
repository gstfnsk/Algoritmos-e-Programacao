/*A. Crie uma função que imprima na tela o menu inicial do jogo apresentando ao usuário as
seguintes opções:
(N) - Novo Jogo
(C) - Carregar Jogo
(M) - Mostrar Créditos
(S) - Sair*/

/*B. Crie uma função que faça a leitura e validação de uma entrada do usuário para seleção da
opção do menu. Esta função deve aceitar como entrada somente os caracteres ‘N’, ‘C’, ‘M’ ou
‘S’ como entrada, portanto, a leitura deve ser repetida até que o usuário digite uma
informação válida. Quando uma entrada válida for informada, a função deve retornar esta
informação. Sempre que uma entrada for inválida, ela deve imprimir na tela “Opcao
invalida” e em seguida mostrar novamente o menu com opções disponíveis.
Dica: Você pode utilizar a função toupper() da biblioteca ctype.h, que recebe um caracter em
minúsculo e transforma o mesmo para maiúsculo. Assim, você permite que o usuário digite
‘n’ para a opção novo Jogo sem ter que explicitamente tratar estas duas entradas. Exemplo
de uso:
char op;
op = toupper(op);*/

/*C. Crie uma função que receba como entrada uma opção digitada pelo usuário (já validada), e
trate esta opção (de forma simplificada), da seguinte forma:
a. Se a opção for ‘N’ (novo jogo), leia o nome do jogador (com até 10 caracteres) e
imprima na tela a mensagem “Jogador XXXXXXXXXX: se prepare, jogo iniciando!!”,
onde “XXXXXXXXXX” será substituído pelo nome digitado.
b. Se a opção for ‘C’ (carregar jogo), o programa deve imprimir na tela a mensagem
“Carregando a lista de jogos salvos, aguarde um minuto.”
c. Se a opção for ‘M’ (mostrar créditos), o programa deve imprimir na tela os créditos
para os desenvolvedores do código, isto é, seu nome e cartao UFRGS.
d. Se a opção for ‘S’ (sair), o programa deve imprimir na tela a mensagem “Encerrando
o jogo, ateh a proxima!” .
*/

/*D. Crie a função main, obrigatória em todo programa C. A função main deve iniciar
imprimindo na tela o nome do jogo Lolo’s Adventure. Ela será a responsável por organizar a
dinâmica da aplicação, chamando as funções auxiliares para fazer as tarefas de impressão
de menu, leitura e validação de entrada, e tratamento de entrada. Seu funcionamento deve
permitir que o programa fique em execução até que o usuário digite ‘S’ para sair. Desta
forma, após mostrar o menu e ler e tratar a entrada do usuário, se a entrada for diferente de
‘S’ ele deve repetir estes passos. O programa termina quando o usuário seleciona a opção de
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

//o tipo da função é o tipo do que ela retorna, no caso não retorna nada

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

