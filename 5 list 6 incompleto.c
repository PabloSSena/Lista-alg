#include<stdio.h>
#define N 2
#include <string.h>

struct ITEM{
    int cod;
    char desc[1000];
    float precCompra;
    float precVenda;
    int quantEst;
    int quantMin;
}item[N]

void cadastrar();

void cadastrar(){
  for(int i = 0; i < N; i++){

      printf("\nDigite o codigo do item:\n");
      scanf("%d",&item[i].cod);

      printf("\nDigite uma descricao:\n");
      scanf("%[^\n]",item[i].desc);

      printf("\nDigite o preco de compra:\n");
      scanf("%f",&item[i].precCompra);

      printf("\nDigite o preco de venda:\n");
      scanf("%f",&item[i].precVenda);

      printf("\nDigite a quantidade atual do estoque:\n");
      scanf("%d",&item[i].quantEst);

      printf("\nDigite a quantidade minima\n");
      scanf("%d",&item[i].quantMin);
  }
}