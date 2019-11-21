#include<stdio.h>
#include <string.h>
#define N 5

struct DADOS{

  char estado[100];
  int vei;
  int aci;
}dados[N];

int acidentes(char est[],int tam){
  int i,cont,max=0,pos;
  float res;

  for(i = 0;i < N;i++){
      cont = dados[i].aci;
      max += cont;
  }
  pos = buscaPosi(est,strlen(est));
  res = dados[i].aci / max;


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

void percentual(char est[],int tam){
    int vei,todo=0,cont,pos;
    float media;

    for(int i = 0;i < N; i++){
        cont = dados[i].vei;
        todo += cont;
    }
    pos = buscaPosi(est,strlen(est));

    media = (dados[pos].vei / todo) * 100;

    printf("Percentual = %f\n",media);
}


int main(){



}
