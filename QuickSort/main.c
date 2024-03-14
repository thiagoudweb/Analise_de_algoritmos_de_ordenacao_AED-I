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

// FUNÇÃO PRINCIPAL: QUICK SORT //
void troca(int *a, int *b, long long *totalSwap) {
    int t = *a;
    *a = *b;
    *b = t;
    (*totalSwap)++;
}

// FUNÇÃO DE PARTIÇÃO DO QUICKSORT //
int particiona(int *vetBubble, int inicio, int fim, long long *totalSwap, long long *totalComp) {
    int pivo = vetBubble[fim];
    int i = (inicio - 1);

    for (int j = inicio; j <= fim - 1; j++) {
        (*totalComp)++;
        if (vetBubble[j] < pivo) {
            i++;
            troca(&vetBubble[i], &vetBubble[j], totalSwap);
        }
    }
    troca(&vetBubble[i + 1], &vetBubble[fim], totalSwap);
    return (i + 1);
}

// FUNÇÃO QUICKSORT //
void quickSort(int *vetBubble, int inicio, int fim, long long *totalSwap, long long *totalComp, clock_t *tempoInicio, long long *totalIteracoes) {
    if (inicio < fim) {
        int pivo = particiona(vetBubble, inicio, fim, totalSwap, totalComp);
        quickSort(vetBubble, inicio, pivo - 1, totalSwap, totalComp, tempoInicio, totalIteracoes);
        quickSort(vetBubble, pivo + 1, fim, totalSwap, totalComp, tempoInicio, totalIteracoes);
    }
}

// MAIN //
int main() {
    srand(10);
    clock_t tempoInicio;
    int vet[TAM_MAX1kk];
    long long totalSwap = 0, totalComp = 0, totalIteracoes = 0;
    int tamVet = TAM_MAX1kk;

    // Escolha uma das opções de lista para testar o algoritmo
    // listaOrdenadaDecrescente(vet, tamVet);
    // listaOrdenada(vet, tamVet);
    // listaParcialmenteOrdenada75(vet, tamVet);
    // createRandomList(vet, tamVet);
    // listaParcialmenteOrdenada50(vet, tamVet);

    tempoInicio = clock();
    quickSort(vet, 0, tamVet - 1, &totalSwap, &totalComp, &tempoInicio, &totalIteracoes);
    tempoInicio = clock() - tempoInicio;

    for (int i = 0; i < tamVet; i++) {
        printf("%d\n", vet[i]);
    }

    printf("Tempo em milisegundos: %f\n", (1000.0 * tempoInicio) / CLOCKS_PER_SEC);
    printf("Numero de trocas: %lld\n", totalSwap);
    printf("Numero de comparações: %lld\n", totalComp);
    printf("Numero de interacoes: %lld\n", totalIteracoes);

    return 0;
}
