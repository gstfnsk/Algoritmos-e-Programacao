/*Uma entrevista no Instituto de Informática consultou 20 alunos. Cada aluno respondeu duas
perguntas:
1) Qual o código do curso que frequenta (1- engenharia de computação; 2- ciência da
computação)?
2) Qual a sua idade?
Ajude os organizadores da pesquisa a analisar estes dados. O seu programa deve
contabilizar, com base nas respostas fornecidas:
A. o número de alunos por curso,
B. o número de alunos com idade entre 20 e 25 anos (inclusive) por curso,
C. o curso com menor média de idades.
Após analisar os dados, imprima na tela, com formatação adequada, as informações pedidas
nos itens A - C (acima)..
O seu programa deve fazer a validação para a entrada da resposta 1). Isto é, somente devem
ser aceitas as opções 1 ou 2. Caso seja digitado um valor diferente destes, o programa deve solicitar
que o usuário digite um novo valor até que o mesmo seja válido.
Assuma que o usuário sempre irá digitar uma idade válida!
*/

#include<stdio.h>
#include<math.h>
#define NUM_ALUNOS 20

int main (){
    int codigoDoCurso, contador, cic = 0, eng = 0, idadeCic, idadeEng, somaIdadeEng = 0, somaIdadeCic = 0;
    int mediaIdadeEng, mediaIdadeCic, eng2 = 0, cic2 = 0;

    for(contador = 0; contador < NUM_ALUNOS; contador++){
        printf("\nDigite o codigo do curso do aluno: \n 1 - engenharia de computacao: \n 2 - ciencia da computacao: \n");
        do{
            scanf("%d", &codigoDoCurso);
            if ((codigoDoCurso != 1) &&(codigoDoCurso != 2)){
                printf("Valor invalido, digite novamente \n");
            }
        }while ((codigoDoCurso != 1) &&(codigoDoCurso != 2)); //verifica se o codigo digitado eh valido

        if (codigoDoCurso == 1){
            eng = eng + 1; //conta o numero de alunos na eng
            printf("Digite a idade do aluno: \n");
            scanf("%d", &idadeEng);
            somaIdadeEng += idadeEng; //variavel acumuladora
            if ((idadeEng >= 20) && (idadeEng <=25)){
                eng2 = eng2 + 1; //conta o numero de alunos na eng que tem entre 20 e 25 anos
            }
        }
        else if (codigoDoCurso == 2){
            cic = cic + 1; //conta o numero de alunos na cic
            printf("Digite a idade do aluno: \n");
            scanf("%d", &idadeCic);
            somaIdadeCic += idadeCic; //variavel acumuladora
             if ((idadeCic >= 20) && (idadeCic <=25)){
                cic2 = cic2 +1; //conta o numero de alunos na cic que tem entre 20 e 25 anos
            }
        }
    }
    printf("Numero de alunos na engenharia de computacao: %d \n", eng);
    printf("Numero de alunos na ciencia da computacao: %d \n \n", cic);
    printf("Numero de alunos com idade entre 20 e 25 anos inclusive na engenharia de computacao: %d \n", eng2);
    printf("Numero de alunos com idade entre 20 e 25 anos inclusive na ciencia da computacao: %d \n", cic2);

    //calculo das medias com as variaveis acumuladoras do for:
    mediaIdadeEng = (float)(somaIdadeEng / eng);
    mediaIdadeCic = (float)(somaIdadeCic / cic);

    //calculo de qual curso tem a menos media de idades
    if (mediaIdadeEng < mediaIdadeCic){
        printf("O curso com menor media de idades eh a engenharia de computacao\n");
    }
    if (mediaIdadeCic < mediaIdadeEng){
        printf("O curso com menor media de idades eh a ciencia da computacao\n");
    }
    else if (mediaIdadeCic == mediaIdadeEng){
            printf("As medias das idades dos dois cursos sao iguais\n");
    }
    return 0;
}

