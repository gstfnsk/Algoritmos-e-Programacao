/* Uma empresa especializada em pistas de dan�a projeta frequentemente pistas circulares. A
proposta da empresa � simples: cobrir a superf�cie da pista com uma resina pr�pria e decorar
suas laterais com uma fita de LED exclusiva. Tanto a resina como a fita de LED possuem pre�os
vari�veis, mas estes s�o sempre dados em fun��o do custo por m� e custo por metro,
respectivamente (por exemplo, em Janeiro o pre�o da resina era R$ 97,00 por m� e o da fita LED
era R$ 65,00 por m).
A empresa precisa de um programa que agilize a confec��o de or�amentos para seus
clientes. A ideia � que o vendedor dever� informar o di�metro (em metros) da pista do cliente, o
pre�o da resina e o pre�o da fita de LED, e o programa imprimir� o or�amento com o pre�o total,
utilizando 3 casas decimais ap�s o ponto.
Al�m disso, a empresa planeja conceder 10% de desconto a compras com valor acima de
R$2500 reais. Assim, nestes casos, seu programa deve imprimir uma mensagem adicional
informando o valor ap�s a aplica��o do desconto. Considerar pi = 3.1415
*/

#include<stdio.h>
#include<math.h>

int main (){

    float diametro, precoResina, precoFitaLED, resina, fitaLED, custoTotal, desconto, pi = 3.1415;

    printf("Digite o diametro da pista: ");
    scanf("%f", &diametro);
    printf("\nDigite o preco da resina: ");
    scanf("%f", &precoResina);
    printf("\nDigite o preco da fita de LED: ");
    scanf("%f", &precoFitaLED);

    resina = precoResina * pi * (diametro/2) * (diametro/2);
    fitaLED = precoFitaLED * 2 * pi * (diametro/2);
    custoTotal = resina + fitaLED;

    printf("\nCusto total da pista: R$ %.3f \n", custoTotal );

    if (custoTotal > 2500){
        printf("Desconto aplicado! Custo final: R$ %.3f \n", custoTotal*0.9);
    }

    return 0;
}

