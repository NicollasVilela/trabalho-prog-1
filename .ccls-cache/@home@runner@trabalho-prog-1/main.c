#include <stdio.h>
#include <string.h>

int main(void) {

  char nome[10][30];
  char nomeCad[30];
  char sexo[10];
  char opc;
  char compras[10];
  int qtdM = 0;
  int qtdF = 0;
  int compNome = 0;
  int compNomeLista = 0;
  float valorTotalCompra[10];
  float valorCompras = 0;
  float somaCompras = 0;
  float compraBarata = 0; 
  float valorTotalM = 0;
  float valorTotal = 0;
  float mediaTotal = 0;

  for(int i= 0; i < 3; i++){
    printf("\nCliente %d: ", i+1);
    scanf("%s", nome[i]);

    do{

      for(int j = 0; j < i; j++){
        compNome = strcmp(nome[i], nome[j]);

      if(compNome == 0){
        printf("Nome já registrado, tente novamente: ");
        scanf("%s", nome[i]);
        j--;
      }
      }
    }while (compNome == 1);

    printf("\nDigite seu sexo (m/f): ");
    scanf(" %c", &sexo[i]);

    if(sexo[i] != 'm' && sexo[i] != 'f'){
      do{
        printf("Sexo inválido, digite m ou f: ");
        scanf(" %c", &sexo[i]);

      }while(sexo [i] != 'm' && sexo[i] != 'f');

    }
    printf("\nDigite o valor total da compra do cliente: ");
    scanf("%f", &valorTotalCompra[i]);

    if(valorTotalCompra[i] < 0){

       do{
         printf("\n---ERRO---\nValor inválido. ");
         scanf("%f", &valorTotalCompra[i]);
       }while(valorTotalCompra[i] < 0);
    }

    if(valorTotalCompra[i] > 0 && (sexo[i] == 'm' || sexo[i] == 'f')){
      printf("\n---Cadastrado---\n");
    }

    if(sexo[i] == 'm'){
      qtdM++;
      valorTotalM += valorTotalCompra[i];
    }else if (sexo[i] == 'f'){
      qtdF++;
    }

    if(compraBarata == 0.0){
      compraBarata = valorTotalCompra[i];
    }else if (valorTotalCompra[i] < compraBarata){
      compraBarata = valorTotalCompra[i];

    }
    somaCompras += valorTotalCompra[i];
  }
   mediaTotal = somaCompras / 3;

  do{
    printf("\nMenu\n");
    printf("\n1 - Ver informações de compras de um cliente ");
    printf("\n2 - Ver informações de todos os produtos ");
    printf("\n3 - Encerrar.\n");
    printf("Digite a opção (1, 2 ou 3): ");
    scanf(" %c", &opc);

    if(opc == '1'){

      printf("\nQual o nome do cliente? ");
      scanf("%s", nomeCad);

     int list = 0; 

      for(int i = 0; i < 3; i++){
        compNomeLista = strcmp(nomeCad, nome[i]);
        if(compNomeLista == 0){
          printf("Sexo: %c\n", sexo[i]);
          printf("Compras: %.2f \n", valorTotalCompra[i]);
          list = 1;
        } 
      }
       if(list != 1){
         printf("\nCliente não encontrado, tente novamente ou entre em contato com o suporte.\n");
       }
    }
    else if(opc == '2'){
      int comprasAcima = 0;
      int comprasAbaixo = 0;
      printf("\nDigite um valor de compras: ");
      scanf("%f", &valorCompras);

      for(int i = 0; i < 3; i++){
       if(valorTotalCompra[i] > valorCompras){
         comprasAcima++;
       }
        if(valorTotalCompra[i] < valorCompras){
          comprasAbaixo++;
        }
       }

      printf("\nCompras acima do valor escolhido: %d\n", comprasAcima);
      printf("\nCompras abaixo do valor escolhido: %d\n", comprasAbaixo);
      printf("\nQuantidade de mulheres: %d\n", qtdF);
      printf("\nValor total dos homens: %.2f\n", valorTotalM);
      printf("\nValor total: %.2f\n", somaCompras);
      printf("\nValor médio: %.2f\n", mediaTotal);
      printf("\nMenor valor: %.2f\n", compraBarata);

    }
    else if (opc == '3'){
     opc = 'n';
    }else{
      printf("\nEscolha outra opção.\n");
    }

    if(opc != 'n'){
     printf("\nDeseja voltar ao menu(s/n): ");
      scanf(" %c", &opc);
    }
  }while (opc != 'n');

   printf("\nFim do programa, volte sempre!");
} 
