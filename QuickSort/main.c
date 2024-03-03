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

void createRandomList(int *vetBubble, int tamVet)
{

    for (int i = 0; i < tamVet; i++)
    {
        vetBubble[i] = rand() % 100000;
    }
}

// FUNÇÃO PARA ORDENAR A LISTA EM 50% //

void listaParcialmenteOrdenada50(int *vetBubble, int tamVet)
{
    int metadeVet = tamVet / 2;

    for (int i = 0; i < metadeVet; i++)
    {
        vetBubble[i] = i;
    }

    for (int i = metadeVet; i < tamVet; i++)
    {
        vetBubble[i] = rand() % 100000;
    }
}

// FUNÇÃO PARA ORDENAR A LISTA EM 75% //

void listaParcialmenteOrdenada75(int *vetBubble, int tamVet)
{

    int metadeVet = (tamVet / 4) * 3;

    for (int i = 0; i < metadeVet; i++)
    {
        vetBubble[i] = i;
    }
    // srand(10);
    for (int i = metadeVet; i < tamVet; i++)
    {
        vetBubble[i] = rand() % 100000;
    }
}

// FUNÇÃO COM A LISTA ORDENADA //
void listaOrdenada(int *vetBubble, int tamVet)
{
    for (int i = 0; i < tamVet; i++)
    {
        vetBubble[i] = i;
    }
}

// FUNÇÃO COM A LISTA ORDENADA DE MANEIRA DECRESCENTE //

void listaOrdenadaDecrescente(int *vetBubble, int tamVet)
{
    int varTemp = tamVet - 1;
    for (int i = 0; i < tamVet; i++)
    {
        vetBubble[varTemp] = i;
        varTemp--;
    }
}

// FUNÇÃO PRINCIPAL: BUBBLE SORT //
void bubbleSort(int *vetBubble, int tamVet, long long *totalSwap, long long *totalInter, clock_t *tempoInicio, long long *totalIteracoes)
{
  
}

// MAIN //
int main()
{
    srand(10);
    clock_t tempoInicio;
    int vet[TAM_MAX1kk];
    long long totalSwap, totalComp, totalnter;
    int tamVet = TAM_MAX1kk;
    //listaOrdenadaDecrescente(vet, tamVet);
    // listaOrdenada(vet, tamVet);
    //listaParcialmenteOrdenada75(vet, tamVet);
    //createRandomList(vet, tamVet);
    listaParcialmenteOrdenada50(vet, tamVet);
    bubbleSort(vet, tamVet, &totalSwap, &totalComp, &tempoInicio, &totalnter);
    for (int i = 0; i < tamVet; i++)
    {
        printf("%d\n", vet[i]);
    }

    printf("Tempo em milisegundos: %f\n", (1000.0 * tempoInicio) / CLOCKS_PER_SEC);
    printf("Numero de trocas: %lld\n", totalSwap);
    printf("Numero de comparações: %lld\n", totalComp);
    printf("Numero de interacoes: %lld\n", totalnter);

    // bubbleSort(vet);

    return 0;
}