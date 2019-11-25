#include<stdio.h>

int main(){

  FILE *arq; //Criando um arquivo.
  char carac = 'a';

  arq = fopen("nomedoarquivo.dat","a"); //Para abrir o arquivo.

  if(arq == NULL) //Teste pra ver se deu certo.
      printf("Erro!!\n");

  

  else{
  do{
     printf("Digite um caractere\n");
     scanf(" %c",&carac);

     fputc(carac,arq);
  }
  while (carac != 0);
  }
  

  fclose(arq); //para fechar o aquivo.


}

//Procurar como evitar o erro <eof>  --TAREFA DE CASA--
