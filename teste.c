#include<stdio.h>
#include<string.h>
#define N 2

struct REGISTRO{

  int cod;
  char nome[51];
  float saldo;
  int ativo;
}cliente[N];

int BuscaPorNomeCompleto(int nome[]);
int buscaPorCodigo(int cod);
void buscaPorNome(char nome[],int tam);
int buscaPosicaovazia();
void cadastraCliente(int pos);
void listaCliente(int pos);
int menu();
void inicializavetor();
void listaTodos();
void removeCliente(int pos);
void alteraCliente(int op,int cod);


void alteraCliente(int op,int cod){
    int  pos;

    pos = buscaPorCodigo(cod);

    switch(op){

        case 1: printf("\nDigite o novo nome:\n");
                scanf(" %[^\n]",cliente[pos].nome);
                listaCliente(pos);
                break;

        case 2: printf("\nDigite o novo codigo:\n");
                scanf("%d",&cliente[pos].cod);
                listaCliente(pos);
                break;

        case 3: printf("\nDigite o novo saldo:\n");
                scanf("%f",&cliente[pos].saldo);
                listaCliente(pos);
                break;        
    }

    

}

void removeCliente(int pos){
     char op;

     listaCliente(pos);

     printf("Remover? (S/N): ");
     scanf(" %c",&op);
     if(op == 's' || op == 'S')
        cliente[pos].ativo = 0;
    
    else
        printf("Ta bao\n");
    
}


int buscaPorNomeCompleto(char nome[]){
  int x = -1;

  for(int i =0;i<N;i++)
     if(strcmp(cliente[i].nome,nome) == 0 && cliente[i].ativo == 1){
        x = i;
        break;
     }

  return x;
}

int buscaPorCodigo(int cod){
    int a = -1,i;

    for(i=0;i<N;i++)
        if(cliente[i].cod == cod && cliente[i].ativo == 1){
           a = i;
           break;
        }
   

    return i;
}

void buscaPorNome (char nome[],int tam){
    int a = -1,i;

    for(i = 0;i<N;i++)
        if(strncmp(cliente[i].nome,nome,tam) == 0 && cliente[i].ativo == 1){
           listaCliente(i);
        }
          
}

int buscaPosicaovazia(){
    int a = -1,i;

    for(i=0;i<N;i++)
        if(cliente[i].ativo == 0){
           a=i;
           break;
    }
    return a;
}

void listaTodos(){
  for(int i=0;i<N;i++)
      if(cliente[i].ativo == 1){
         printf("Cliente = %s\n",cliente[i].nome);
         printf("Codigo = %d\n",cliente[i].cod);
         printf("saldo = %f\n",cliente[i].saldo);
         printf("Ativo = %d\n",cliente[i].ativo);
         printf("\n\n");
}
}

void inicializavetor(){
  for(int i=0;i< N;i++){
      cliente[i].saldo = 0;
      cliente[i].ativo = 0;
}
}

void cadastraCliente(int pos){

      printf("Nome: \n");
      scanf(" %[^\n]",cliente[pos].nome);

      printf("Codigo: \n");
      scanf(" %d",&cliente[pos].cod);

      printf("Saldo: \n");
      scanf(" %f",&cliente[pos].saldo);

      cliente[pos].ativo = 1;
      printf("\n");

   }



void listaCliente(int pos){
  if(cliente[pos].ativo == 1){  
  printf("Código = %d\n",cliente[pos].cod);
  printf("Nome = %s\n",cliente[pos].nome);
  printf("Saldo = %f\n",cliente[pos].saldo);
  printf("\n");
  }
}

int menu(){
  int op;

  printf("1 - Para cadastrar clientes\n2 - Para listar todos os cliente\n3 - Lista clientes por nome\n4 - Remove cliente\n5 - Altera cliente\n");
  scanf("%d",&op);
  printf("\n");
  return op;
}

int main(){

  int opc,opca,op,posi,atual,cod;
  char slurps[52];
  
  inicializavetor();
  
  do{

  op = menu();

  switch(op){

   case 1:  atual = buscaPosicaovazia();
            if(atual!= -1){
               cadastraCliente(atual);
           }

           else
               printf("Vetor cheio\n");
           break;

  case 2:  listaTodos();
           break;

  case 3: printf("Nome do cliente:\n");
          scanf(" %[^\n]",slurps);
          
          buscaPorNome(slurps,strlen(slurps));
          break;

  case 4: printf("1 - Por nome\n2 - Por codigo\nOpçao:\n");
          scanf("%d",&atual);
          
          
          switch(atual){
                 case 1 : printf("Nome do cliente:\n");
                          scanf(" %[^\n]",slurps);
                          
                          int pesquisa = buscaPorNomeCompleto (slurps);

                          if(pesquisa != -1)
                             removeCliente(pesquisa);

                          else
                              printf("Cliente nao escontrado\n");
                              break;

                    case 2: printf("Digite o codigo:\n");
                            scanf("%d",&cod);

                            pesquisa = buscaPorCodigo(cod);

                            if(pesquisa != -1)
                               removeCliente(pesquisa);

                            else
                                printf("Não encontrado");
                                break;
          }
          break;

    case 5: printf("Digite o codigo\n");
            scanf("%d",&cod);
            
            printf("\nDeseja alterar o que?\n1 - Nome\n2 - Codigo\n3 - Saldo\n");
            scanf("%d",&opca);

            alteraCliente(opca,cod);
 
                     
            break;

  case 0:printf("Finalizado\n");
         break;

  default: printf("Invalido\n");
  }
  }
  while(op !=0);
}