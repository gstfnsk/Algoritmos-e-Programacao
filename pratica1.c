/*PROBLEMA 1:
A empresa X deseja aumentar suas receitas em 2020, e para estimular os vendedores
contratados e buscar este aumento, estipulou que cada vendedor ganhará uma comissão por
venda, oferecendo um percentual (pré-estabelecido) sobre o valor da venda realizada. Esta
comissão pode variar de vendedor para vendedor, assim como o conteúdo da venda (valor do
produto e quantidade), portanto, foi solicitada a sua ajuda para automatizar esse processo Faça
um programa que informe o valor (em reais) da comissão de um vendedor dado o valor unitário
do produto vendido, a quantidade de itens vendidos, e o percentual usado para cálculo da
comissão.  */

#include<stdio.h>
#include<math.h>

int main (){
    float valorProduto, percentualComissao, valorComissao, totalVenda;
    int quantidadeVendida;

    printf ("Digite o valor do produto: R$");
    scanf ("%f", &valorProduto);
    printf ("\n Digite a quantidade de produtos:");
    scanf ("%d", &quantidadeVendida);
    printf ("\n Digite o percentual de comissao:");
    scanf ("%f", &percentualComissao);

    totalVenda =  valorProduto * quantidadeVendida;
    valorComissao =  (totalVenda * percentualComissao)/100;

    printf ("\n=====Registro  de venda===== \n");
    printf ("Valor do produto: R$%.2f \n", valorProduto);
    printf ("Quantidade vendida: %d \n", quantidadeVendida);
    printf ("Total da venda: R$%.2f \n", totalVenda);
    printf ("Valor da comissao do vendedor: R$%.2f \n", valorComissao);

    return 0;
}



