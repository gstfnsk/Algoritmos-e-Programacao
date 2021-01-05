
#include<stdio.h>
#include <stdlib.h>
#define NLIN 6
#define NCOL 6
#define MIN 0
#define MAX 100

int oMaior(int matriz[][NCOL], int num_lin, int num_col, int *pos_lin, int *pos_col){
    int i, j, lin=0, col=0, maior=matriz[0][0];
    /*printf("A matriz gerada foi: \n\n");
    for (i=0; i<num_lin; i++){
        for (j=0; j< num_col; j++){
            printf("%5d", matriz[i][j]);
        }
        printf("\n\n");
    }*/
    for (i=0; i<num_lin; i++){
        for (j=0; j<num_col; j++){
            if (matriz[i][j] > maior){
                maior = matriz[i][j];
                lin=i;
                col=j;
            }
        }
    }
    *pos_lin=lin;
    *pos_col=col;
    return maior;
}

int main(){
    int lin, col, guardaLin, guardaCol, maiorElemento;
    int matriz[NLIN][NCOL];
    srand(time(NULL));
    for (lin=0; lin<NLIN; lin++){
        for (col=0; col< NCOL; col++){
            matriz[lin][col]=(MIN + (rand()%(MAX-MIN+1)));
        }
    }
    printf("A matriz gerada foi: \n\n");
    for (lin=0; lin<NLIN; lin++){
        for (col=0; col< NCOL; col++){
            printf("%5d", matriz[lin][col]);
        }
        printf("\n\n");
    }
    maiorElemento=oMaior(matriz, NLIN, NCOL, &guardaLin, &guardaCol);
    printf("\nO maior elemento da matriz acima eh %d e esta localizado na linha %d e coluna %d", maiorElemento, guardaLin+1, guardaCol+1);
    return 0;
}
