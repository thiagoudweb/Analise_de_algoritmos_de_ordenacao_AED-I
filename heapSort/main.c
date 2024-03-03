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

// Função para ajustar o heap
void heapify(int *vet, int n, int i, long long *totalSwap, long long *totalComp) {
    int maior = i; 
    int esq = 2 * i + 1; 
    int dir = 2 * i + 2; 

    // Se o filho da esquerda é maior que a raiz
    if (esq < n && vet[esq] > vet[maior]) {
        maior = esq;
        (*totalComp)++;
    }

    // Se o filho da direita é maior que o maior até agora
    if (dir < n && vet[dir] > vet[maior]) {
        maior = dir;
        (*totalComp)++;
    }

    // Se o maior não é raiz
    if (maior != i) {
        int swap = vet[i];
        vet[i] = vet[maior];
        vet[maior] = swap;

        (*totalSwap)++;

        // Recursivamente heapify a sub-árvore afetada
        heapify(vet, n, maior, totalSwap, totalComp);
    }
}

// Função principal para realizar o heapSort
void heapSort(int *vet, int n, long long *totalSwap, long long *totalComp) {
    // Construir heap (rearranjar array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vet, n, i, totalSwap, totalComp);

    // Extrair um por um os elementos do heap
    for (int i = n - 1; i > 0; i--) {
        // Mover a raiz atual para o fim
        int temp = vet[0];
        vet[0] = vet[i];
        vet[i] = temp;

        (*totalSwap)++;

        // chamar max heapify na heap reduzida
        heapify(vet, i, 0, totalSwap, totalComp);
    }
}

// MAIN //
int main() {
    srand(10);
    clock_t tempoInicio, tempoFim;
    int vet[TAM_MAX50K];
    long long totalSwap = 0, totalComp = 0;
    int tamVet = TAM_MAX50K;

    // Escolha uma das opções de lista para testar o algoritmo de ordenação
    // listaOrdenadaDecrescente(vet, tamVet);
    // listaOrdenada(vet, tamVet);
    // listaParcialmenteOrdenada75(vet, tamVet);
    // createRandomList(vet, tamVet);
    listaParcialmenteOrdenada50(vet, tamVet);

    tempoInicio = clock();
    heapSort(vet, tamVet, &totalSwap, &totalComp);
    tempoFim = clock();

    for (int i = 0; i < tamVet; i++) {
        printf("%d\n", vet[i]);
    }

    printf("Tempo em milisegundos: %f\n", (1000.0 * (tempoFim - tempoInicio)) / CLOCKS_PER_SEC);
    printf("Numero de trocas: %lld\n", totalSwap);
    printf("Numero de comparações: %lld\n", totalComp);

    return 0;
}
