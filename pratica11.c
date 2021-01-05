#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define TAM 20

typedef struct {
    char nome[80];
    char telefone[15];
    char vinculo[30];
    int sala;
    int predio;
} funcionario_st;

void lista_dados_funcionarios(char*);

void adiciona_funcionario(char*);

void atualiza_sala_e_predio(char*);

int main(){
    funcionario_st funcionario;
    FILE *arquivo;
    int op;
    char nome[TAM+1] = "inf.bin";
    lista_dados_funcionarios(nome);
    adiciona_funcionario(nome);
    atualiza_sala_e_predio(nome);
    printf("Lista de funcionarios atualizada:\n");
    lista_dados_funcionarios(nome);
    return 0;
}

// QUESTÃO A)
void lista_dados_funcionarios(char* nome_arquivo){
    FILE *arquivo;
    funcionario_st func;
    if(!(arquivo = fopen(nome_arquivo,"rb"))){
        printf("Erro na leitura");
    }
    else{
        printf("Lista de todos os dados dos funcionarios:\n");
        while(!feof(arquivo)) {
            if (fread(&func,sizeof(funcionario_st),1,arquivo) == 1) {
                printf("\nFuncionario: %s \nTelefone: %s \nVinculo: %s \nSala: %d \nPredio: %d\n\n\n", func.nome, func.telefone, func.vinculo, func.sala, func.predio);
            }
        }
        fclose(arquivo);
    }
}

// QUESTÃO B
void adiciona_funcionario(char* nome_arquivo){
    FILE *arquivo;
    funcionario_st func;
    int op, sim;
    rewind(arquivo);
    if(!(arquivo = fopen(nome_arquivo,"ab"))){
        printf("Erro na abertura para acrescentar");
    }
    else{
        printf("\nAdiciona funcionario:\n");
        printf("\nDigite 1 se voce deseja adicionar um funcionario, senao, digite qualquer outro numero: ");
        scanf("%d", &sim);
        if (sim == 1){
            do {
                fflush(stdin);
                printf("\nEntre um novo registro de funcionario:\n");
                printf("\nNome (ate 79 caracteres): ");
                fgets(func.nome, 80, stdin);
                func.nome[ strlen(func.nome)-1 ] = '\0'; //remove '\n'
                printf("\nTelefone: ");
                fgets(func.telefone, 15, stdin);
                func.telefone[ strlen(func.telefone)-1 ] = '\0';
                printf("\nVinculo: ");
                fgets(func.vinculo, 30, stdin);
                func.vinculo[ strlen(func.vinculo)-1 ] = '\0';
                printf("\nSala: ");
                scanf("%d", &func.sala);
                printf("\nPredio: ");
                scanf("%d", &func.predio);
                if (fwrite(&func,sizeof(funcionario_st),1,arquivo) != 1){
                    printf("Erro de escrita!\n");
                }
                printf("\nDigite 1 para adicionar novo funcionario e 2 para sair: ");
                do{
                    scanf("%d", &op);
                    if ((op != 1) && (op != 2)){
                        printf ("\nDigite apenas 1 ou 2!\n");
                    }
                }while((op != 1) && (op != 2));
            }while(op != 2);
        }
    }
    fclose(arquivo);
}

//QUESTÃO C
void atualiza_sala_e_predio(char* nome_arquivo){
    FILE *arquivo;
    funcionario_st func;
    char nome_procurado[80];
    int encontrado, op, sim;
    if(!(arquivo = fopen(nome_arquivo,"r+b"))){
        printf("\nErro na abertura para atualizar");
    }
    else {
        printf("\nDigite 1 se voce quer atualizar a sala e predio de um funcionario, senao, digite qualquer outro numero: \n");
        scanf("%d", &sim);
        if (sim == 1){
            do {
                fflush(stdin);
                rewind(arquivo);
                printf("\nDigite o nome do funcionario para atualizar sua sala e predio: ");
                fgets(nome_procurado, 80, stdin);
                nome_procurado[ strlen(nome_procurado)-1 ] = '\0';
                encontrado=0;
                while(!feof(arquivo) && !encontrado){ //para qdo. acha ou no fim do arquivo
                    if(fread(&func,sizeof(funcionario_st),1,arquivo) == 1){
                        if(strncmp(func.nome, nome_procurado, 80) == 0){
                            printf("\nSala cadastrada: %d \n\nPredio cadastrado: %d\n", func.sala, func.predio);
                            printf("\nInforme alteracao da sala: ");
                            scanf("%d",&func.sala);
                            printf("\nInforme alteracao do predio: ");
                            scanf("%d",&func.predio);
                            // posiciona no lugar anterior à leitura, usando
                            // deslocamento negativo a partir da posição corrente
                            fseek(arquivo, -sizeof(funcionario_st),SEEK_CUR);
                            //substitui, verificando se gravação foi bem sucedida
                            if(fwrite(&func,sizeof(funcionario_st),1,arquivo) != 1){
                                printf("\nErro de gravacao\n");
                            }
                            encontrado = 1;
                            printf("\nA atualizacao foi bem sucedida\n");
                        }
                    }
                }
                if (!encontrado){
                    printf("\nNao foi encontrado funcionario com esse nome no arquivo\n");
                }
                printf("\nDigite 1 para atualizar a sala e o predio de mais um funcionario ou 2 para sair\n");
                do{
                    scanf("%d", &op);
                    if ((op != 1) && (op != 2)){
                        printf("\nDigite apenas 1 ou 2!\n");
                    }
                }while((op != 1) && (op != 2));
            }while(op != 2);
        }
    }
    fclose(arquivo);
}
