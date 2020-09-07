/*De acordo com o crit�rio de avalia��o da disciplina de Algoritmos e Programa��o, um aluno
ser� aprovado se tiver m�dia final maior ou igual a 6,0 e frequ�ncia m�nima de 75%. A m�dia final
da disciplina � calculada como:
M�dia Final = 0,3 * P1 + 0,45 * P2 + 0,15 * AP + 0,10 TF
Onde P1 e P2 s�o as notas das provas 1 e 2, AP � a nota das atividades pr�ticas, e TF � a nota do
trabalho final. Assuma que as notas digitadas ser�o sempre valores entre 0 e 10. Fa�a um programa
que leia as 4 notas de um aluno e a sua frequ�ncia, e informe a m�dia final do aluno (com duas
casas decimais), se o aluno foi aprovado ou reprovado na disciplina e o respectivo conceito.
Lembre-se que o conceito final � obtido da seguinte forma:
Se a nota for maior ou igual que 8,5 ---> A
Se a nota final ficar entre 7,5 (inclusive) e 8,5 ---> B
Se a nota final ficar entre 6,0 (inclusive) e 7,5 ---> C
Se a nota final ficar abaixo de 6,0 ---> D
Se o aluno n�o alcan�ar a frequ�ncia m�nima (75%) ---> FF

*/

#include<stdio.h>
#include<math.h>

int main(){
    float P1, P2, AP, TF, frequencia, mediaFinal;
    printf("Digite as 4 notas do aluno e sua frequencia nas aulas: \n");
    scanf("%f %f %f %f %f", &P1, &P2, &AP, &TF, &frequencia);

    mediaFinal = (0.3 * P1) + (0.45 * P2) + (0.15 * AP) + (0.1 * TF);
    printf("Media Final: %.2f \n", mediaFinal);

    if (frequencia <= 0.75){
        printf ("Aluno reprovado com FF (Frequencia < 75%%!)\n");
    }
    else {
        if (mediaFinal < 6){
            printf("Aluno reprovado com D.\n");
        }
        if ((mediaFinal >= 6) && (mediaFinal < 7.5 )){
            printf("Aluno aprovado com C.\n");
        }
        if ((mediaFinal >= 7.5) && (mediaFinal < 8.5)){
            printf("Aluno aprovado com B.\n");
        }
        if ((mediaFinal >= 8.5) && (mediaFinal <=10)) {
            printf("Aluno aprovado com A.\n");
        }
    }
    return 0;
}
