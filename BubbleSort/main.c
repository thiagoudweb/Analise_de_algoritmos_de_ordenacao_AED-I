#include <stdio.h>
#include <stdlib.h>
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
void createRandomList(int *vetBubble, int tamVet) {
    for (int i = 0; i < tamVet; i++) {
        vetBubble[i] = rand() % 100000;
    }
}

// FUNÇÃO PARA ORDENAR A LISTA EM 50% //
void listaParcialmenteOrdenada50(int *vetBubble, int tamVet) {
    int metadeVet = tamVet / 2;
    for (int i = 0; i < metadeVet; i++) {
        vetBubble[i] = i;
    }
    for (int i = metadeVet; i < tamVet; i++) {
        vetBubble[i] = rand() % 100000;
    }
}

// FUNÇÃO PARA ORDENAR A LISTA EM 75% //
void listaParcialmenteOrdenada75(int *vetBubble, int tamVet) {
    int metadeVet = (tamVet / 4) * 3;
    for (int i = 0; i < metadeVet; i++) {
        vetBubble[i] = i;
    }
    for (int i = metadeVet; i < tamVet; i++) {
        vetBubble[i] = rand() % 100000;
    }
}

// FUNÇÃO COM A LISTA ORDENADA //
void listaOrdenada(int *vetBubble, int tamVet) {
    for (int i = 0; i < tamVet; i++) {
        vetBubble[i] = i;
    }
}

// FUNÇÃO COM A LISTA ORDENADA DE MANEIRA DECRESCENTE //
void listaOrdenadaDecrescente(int *vetBubble, int tamVet) {
    int varTemp = tamVet - 1;
    for (int i = 0; i < tamVet; i++) {
        vetBubble[varTemp] = i;
        varTemp--;
    }
}

// FUNÇÃO PARA AJUSTAS O HEAP //
void heapify(int *vet, int n, int i, long long *totalSwap, long long *totalComp, long long *totalIteracoes) {
    int maior = i; 
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2; 
    (*totalIteracoes)++; 


    if (esq < n && vet[esq] > vet[maior]) {
        maior = esq;
        (*totalComp)++;
    }

    if (dir < n && vet[dir] > vet[maior]) {
        maior = dir;
        (*totalComp)++;
    }

    if (maior != i) {
        int swap = vet[i];
        vet[i] = vet[maior];
        vet[maior] = swap;

        (*totalSwap)++;


        heapify(vet, n, maior, totalSwap, totalComp, totalIteracoes);
    }
}

// FUNÇÃO PARA REALIZAR O HEAP
void heapSort(int *vet, int n, long long *totalSwap, long long *totalComp, long long *totalIteracoes) {

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(vet, n, i, totalSwap, totalComp, totalIteracoes);
    }

    for (int i = n - 1; i > 0; i--) {

        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;

        (*totalSwap)++;


        heapify(vet, i, 0, totalSwap, totalComp, totalIteracoes);
    }
}

// MAIN //
int main() {
    srand(10);
    clock_t tempoInicio, tempoFim;
    int vet[TAM_MAX10K];
    long long totalSwap = 0, totalComp = 0, totalIteracoes = 0;
    int tamVet = TAM_MAX10K;

    // Escolha uma das opções de lista para testar o algoritmo de ordenação
    // listaOrdenadaDecrescente(vet, tamVet);
    // listaOrdenada(vet, tamVet);
    //listaParcialmenteOrdenada75(vet, tamVet);
    // createRandomList(vet, tamVet);
    //listaParcialmenteOrdenada50(vet, tamVet);

    tempoInicio = clock();
    heapSort(vet, tamVet, &totalSwap, &totalComp, &totalIteracoes);
    tempoFim = clock();

    for (int i = 0; i < tamVet; i++) {
        printf("%d\n", vet[i]);
    }

    printf("Tempo em milisegundos: %f\n", (1000.0 * (tempoFim - tempoInicio)) / CLOCKS_PER_SEC);
    printf("Numero de trocas: %lld\n", totalSwap);
    printf("Numero de comparações: %lld\n", totalComp);
    printf("Numero de iterações: %lld\n", totalIteracoes);

    return 0;
}
