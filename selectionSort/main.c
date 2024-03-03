#include <stdio.h>
#include <time.h>

// TAMANHO DOS VETORES
#define TAM_MAX10K 10000
#define TAM_MAX50K 50000
#define TAM_MAX100k 100000
#define TAM_MAX500k 500000
#define TAM_MAX1kk 1000000
#define TAM_MAX10kk 10000000
#define TAM_MAX50kk 50000000

// FUNÇÃO PARA GERAR LISTAS ALEATÓRIAS //

void createRandomList(int *vetSelection, int tamVet) {
  // srand(10);
  for (int i = 0; i < tamVet; i++) {
    vetSelection[i] = rand() % 100000;
  }
}

// FUNÇÃO PARA ORDENAR A LISTA EM 50% //

void listaParcialmenteOrdenada50(int *vetSelection, int tamVet) {
  int metadeVet = tamVet / 2;

  for (int i = 0; i < metadeVet; i++) {
    vetSelection[i] = i;
  }
  // srand(10);
  for (int i = metadeVet; i < tamVet; i++) {
    vetSelection[i] = rand() % 100000;
  }
}

// FUNÇÃO PARA ORDENAR A LISTA EM 75% //

void listaParcialmenteOrdenada75(int *vetSelection, int tamVet) {

  int metadeVet = (tamVet / 4) * 3;

  for (int i = 0; i < metadeVet; i++) {
    vetSelection[i] = i;
  }
  // srand(10);
  for (int i = metadeVet; i < tamVet; i++) {
    vetSelection[i] = rand() % 100000;
  }
}

// FUNÇÃO COM A LISTA ORDENADA //
void listaOrdenada(int *vetSelection, int tamVet) {
  for (int i = 0; i < tamVet; i++) {
    vetSelection[i] = i;
  }
}

// FUNÇÃO COM A LISTA ORDENADA DE MANEIRA DECRESCENTE //

void listaOrdenadaDecrescente(int *vetSelection, int tamVet) {
  int varTemp = tamVet - 1;
  for (int i = 0; i < tamVet; i++) {
    vetSelection[varTemp] = i;
    varTemp--;
  }
}

// FUNÇÃO PRINCIPAL: SELECTION SORT //
void selectionSort(int *vetSelection, int tamVet, long *totalSwap,
                   long *totalInter, clock_t *tempoInicio,
                   long *totalIteracoes) {
  long varTemp, contSwap = 0, contInter = 0, contIteracoes = 0;
  int bolBreak;
  int minimo;
  *tempoInicio = clock();
  for (int i = 0; i < tamVet - 1; i++) {
    minimo = i;
    bolBreak = 0;
    contIteracoes++;
    for (int j = i + 1; j < tamVet; j++){
      if (vetSelection[j] < vetSelection[minimo]){
        minimo = j;
      }
      if (minimo != i){
        varTemp = vetSelection[minimo];
        vetSelection[minimo] = vetSelection[i];
        vetSelection[i] = varTemp;
        contSwap++;
      }
      contInter++;
      bolBreak = 1;
      }
    if (bolBreak == 0){
      break;
    }
  }
  
  *tempoInicio = clock() - *tempoInicio;
  *totalIteracoes = contIteracoes;
  *totalSwap = contSwap;
  *totalInter = contInter;
}

// MAIN //
int main() {
  srand(10);
  clock_t tempoInicio;
  int vet[10];
  long totalSwap, totalComp, totalnter;
  int tamVet = 10;
   //listaOrdenadaDecrescente(vet, tamVet);
  listaOrdenada(vet, tamVet);
  // listaParcialmenteOrdenada75(vet, tamVet);
  //  createRandomList(vet, tamVet);
  //  listaParcialmenteOrdenada50(vet, tamVet);
  selectionSort(vet, tamVet, &totalSwap, &totalComp, &tempoInicio, &totalnter);
  for (int i = 0; i < tamVet; i++) {
    printf("%d\n", vet[i]);
  }

  printf("Tempo em milisegundos: %f\n",
         (1000.0 * tempoInicio) / CLOCKS_PER_SEC);
  printf("Numero de trocas: %ld\n", totalSwap);
  printf("Numero de comparações: %ld\n", totalComp);
  printf("Numero de interacoes: %ld\n", totalnter);

  // selectionSort(vet);

  return 0;
}
