/*De acordo com o critério de avaliação da disciplina de Algoritmos e Programação, um aluno
será aprovado se tiver média final maior ou igual a 6,0 e frequência mínima de 75%. A média final
da disciplina é calculada como:
Média Final = 0,3 * P1 + 0,45 * P2 + 0,15 * AP + 0,10 TF
Onde P1 e P2 são as notas das provas 1 e 2, AP é a nota das atividades práticas, e TF é a nota do
trabalho final. Assuma que as notas digitadas serão sempre valores entre 0 e 10. Faça um programa
que leia as 4 notas de um aluno e a sua frequência, e informe a média final do aluno (com duas
casas decimais), se o aluno foi aprovado ou reprovado na disciplina e o respectivo conceito.
Lembre-se que o conceito final é obtido da seguinte forma:
Se a nota for maior ou igual que 8,5 ---> A
Se a nota final ficar entre 7,5 (inclusive) e 8,5 ---> B
Se a nota final ficar entre 6,0 (inclusive) e 7,5 ---> C
Se a nota final ficar abaixo de 6,0 ---> D
Se o aluno não alcançar a frequência mínima (75%) ---> FF

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
