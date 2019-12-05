#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 100



int main(){
  char tent,op,tentM,tentN,c,ini[N];
  int chan=6,tam,i,pos,cont=0,gan = 0,perd = 0,gan2 = 0;

  FILE *sec;

  sec = fopen("segredo.txt","r");

  if(sec == NULL)
     printf("Deu erro\n");


  else{
      fscanf(sec," %[^\n]",ini);
      tam = strlen(ini);

      char seg[tam],tenta[tam],acertos[tam],erros[7];

      strcpy(seg,ini);

       printf("\t\t\tNumero de letras = %d\n",tam);
       printf("\t\t\tDica = Um lugar\n\n");

       for(i=0;i<6;i++)
           erros[i] = '*';

       for(i=0;i<tam;i++)
           acertos[i] = '_';

    do{
       //Printando os * e letras//
       printf("Erros:");
       for(i=0;i<6;i++)
           printf(" %c",erros[i]);

        //desenhos//
       if(chan == 6)
          printf("\n |==|\n |\n |\n |\n |\n/ \\");

       if(chan == 5)
         printf("\n |==|\n |  o\n |\n |\n |\n/ \\");

       if(chan == 4)
         printf("\n |==|\n |  o\n |  |\n |\n |\n/ \\");

       if(chan == 3)
         printf("\n |==|\n |  o\n | /|\n |\n |\n/ \\");

       if(chan == 2)
         printf("\n |==|\n |  o\n | /|\\\n |\n |\n/ \\");

       if(chan == 1)
         printf("\n |==|\n |  o\n | /|\\\n | /\n | \n/ \\");

       //Printando os _ e letras//
       for(i=0;i<tam;i++)
           printf(" %c",acertos[i]);


       printf("\n1 - Para tentar uma letra\n2 - Para tentar a frase\n");
       scanf(" %c",&op);
       while(op != '1' && op != '2'){
            printf("Digita 1 ou 2 fi!\n"); 
            scanf(" %c",&op);
       }
         switch(op){

           case '1':printf("\nLetra = ");
                  scanf(" %c",&tent);

                  tentM = toupper(tent);
                  tentN = tolower(tent);
                  cont = 0;

                  for(i=0;i<tam;i++){
                     if(seg[i] == tent||seg[i] == tentM||seg[i] == tentN){
                        pos = i;
                        cont++;
                        acertos[pos] = tentM;
                     }
                  }
                  if(cont == 0){
                     erros[chan-1] = tent;
                     chan--;
                  }

                  if(strcasecmp(acertos,seg) == 1)
                     gan2 = 1;

                  printf("\n\n");
                  break;

            case '2':printf("\nDigite a frase = ");
                   scanf(" %[^\n]",tenta);

                   if(strcasecmp(tenta,seg) == 0)
                      gan = 1;

                   else
                      perd = 1;
                  break;
         }
    }
     while(gan == 0 && perd == 0 && chan != 0 && gan2 == 0);

     if(gan == 1 || gan2 == 1){
        printf("\n!!!!!!!!!!Parabens voce ganhou!!!!!!!!!!\n!!!!!!!!!!A palavra era: %s!!!!!!!!!!\n\n",seg);

     }

     if(perd == 1 || chan == 0){
        printf("\n |==|\n |  o\n | /|\\\n | / \\\n | \n/ \\");
        printf("\t\tPerdeste\n");
        printf("\t\tA palavra era: %s\n",seg);

     }
  }
}