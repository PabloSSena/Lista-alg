#include<stdio.h>

int main(){
  int f,r,gt1,gt2,cont=0,para=0,i=0,teste=0,num=0,soma=0,j,k;

  FILE *arq;

  arq = fopen("entrada.txt","r");

  if(arq == NULL)
     printf("Deu erro\n");

  else{
     fscanf(arq,"%d %d %d %d",&f,&r,&gt1,&gt2);

  if(f >=1 && f <= 100000 && r >=1 && r <= 1000){
         gt1 -= 1;
         gt2 -= 1;

         int fita[f];

         fita[gt1] = 1;
         fita[gt2] = 1;

         for(i=0;i<f;i++){
             soma = 0;
             if(gt1+i < f)
                fita[gt1+i] = 1;

             if(gt1-i >= 0)
                fita[gt1-i] = 1;

             if(gt2+i < f)
                fita[gt2+i] = 1;

             if(gt2-i >= 0)
                fita[gt2-i] = 1;


             for(j=0;j<f;j++){
                 num = fita[j];
                 soma += num;
                 if(soma == f && para == 0){
                    cont = i;
                    para++;
                  }
              }
         }

        printf("\n%d\n",cont);
      }
  else
    printf("Erro!\n");
  }
  fclose(arq);
}




