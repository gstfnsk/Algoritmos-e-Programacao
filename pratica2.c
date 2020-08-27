/* Uma empresa especializada em pistas de dança projeta frequentemente pistas circulares. A
proposta da empresa é simples: cobrir a superfície da pista com uma resina própria e decorar
suas laterais com uma fita de LED exclusiva. Tanto a resina como a fita de LED possuem preços
variáveis, mas estes são sempre dados em função do custo por m² e custo por metro,
respectivamente (por exemplo, em Janeiro o preço da resina era R$ 97,00 por m² e o da fita LED
era R$ 65,00 por m).
A empresa precisa de um programa que agilize a confecção de orçamentos para seus
clientes. A ideia é que o vendedor deverá informar o diâmetro (em metros) da pista do cliente, o
preço da resina e o preço da fita de LED, e o programa imprimirá o orçamento com o preço total,
utilizando 3 casas decimais após o ponto.
Além disso, a empresa planeja conceder 10% de desconto a compras com valor acima de
R$2500 reais. Assim, nestes casos, seu programa deve imprimir uma mensagem adicional
informando o valor após a aplicação do desconto. Considerar pi = 3.1415
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

