#include<stdio.h>

int main(){
  int f,r,gt1,gt2,cont =0,para,i,teste=0;
  FILE *arq;

  arq = fopen("entrada.txt","r");

  if(arq == NULL)
     printf("Deu erro\n");

  else{
     printf("Deu certo\n");
     fscanf(arq,"%d %d %d %d",&f,&r,&gt1,&gt2);

     printf("%d %d %d %d\n",f,r,gt1,gt2);

     int fita[f];
     fita[gt1] = 1;
     fita[gt2] = 1;

     do{
        for(i = 0;i < f; i++){
            if(fita[i] != 1){
                if(gt1 - i > 0 || gt1 + i < f){
                   fita[gt1-i] = 1;
                   fita[gt2+i] = 1;
                }
                if(gt2 - i > 0 || gt2 + i < f){
                   fita[gt1-i] = 1;
                   fita[gt2+i] = 1;
                }
            }
            else
                teste++;

            cont++;
        }

    }
    while(cont == 0);

    printf("Dias = %d\n",cont);
}
}
