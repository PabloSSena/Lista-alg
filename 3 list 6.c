#include<stdio.h>
#include <string.h>
#define N 5

struct DADOS{

  char estado[100];
  int vei;
  int aci;
}dados[N];

float acidentes(char est[],int tam){

  int i,cont,max = 0,pos;
  float res;

  for(i = 0;i < N;i++){                                                                                                                                                                                                                     
      cont = dados[i].aci;
      max += cont;
  }
  pos = buscaPosi(est,strlen(est));
  res = dados[i].aci / max;
  
  return res;
}

int buscaPosi(char estado[],int tam){

    int pos;

  for(int i=0;i<N;i++){
      if(strcmp(estado,dados[i].estado) == 0)
         pos = i;
  }
  return pos;
}
void preenche(){
    for(int i = 0; i < N; i++){
        printf("Estado: \n");
        scanf(" %[^\n]",dados[i].estado);

        printf("Quantidade de veiculos: \n");
        scanf("%d",&dados[i].vei);

        printf("Quantidade de acidentes: \n");
        scanf("%d",&dados[i].aci);

    }
}

void maior(){
    int maior,menor;
    char estadoM[100],estadoN[100];

    maior = dados[0].aci;
    menor = dados[0].aci;

    for(int i = 0; i < N; i++){
        if(dados[i].aci > maior)
           maior = dados[i].aci;
           strcpy(estadoM,dados[i].estado);

        if(dados[i].aci < menor)
           menor = dados[i].aci;
           strcpy(estadoN,dados[i].estado);

    }

    printf("Maior indice = %d\nEstado = %s\n\n",maior,estadoM);
    printf("Menor indice = %d\nEstado = %s\n\n",menor,estadoN);
}

float percentual(char est[],int tam){
    int vei,todo=0,cont,pos;
    float media;

    for(int i = 0;i < N; i++){
        cont = dados[i].vei;
        todo += cont;
    }
    pos = buscaPosi(est,strlen(est));

    media = (dados[pos].vei / todo) * 100;

    return media;
}

int menu(){

    int op;

    printf("O que deseja saber?\n1 - Qual o maior e o menor índice de acidentes de trânsito e o nome dos estados em que eles ocorreram.\n2 - Qual o percentual de veículos em cada estado.\n3 - Qual a média de acidentes em cada um dos estados.\n0 - Para sair");
    printf("Opcao :\n");
    scanf("%d",&op);

    return op;
}


int main(){

    int op;
    char estado[100];
    float perc;
    preenche();

    do{
        op = menu();

        switch(op){

            case 1: maior();
                    break;

            case 2: printf("Digite o nome do estado:\n");
                    scanf("%[^\n]",estado);

                   perc = percentual(estado,strlen(estado));
                   printf("Percentual = %f\n",perc);
                   break;

            case 3:printf("Digite o nome do estado:\n");
                   scanf("%[^\n]",estado);

                   perc = acidentes(estado,strlen(estado));
        }
         
    }
    while(op!=0);



}