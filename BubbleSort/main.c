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
    // srand(10);
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
    // srand(10);
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
void bubbleSort(int *vetBubble, int tamVet, long *totalSwap, long *totalInter, clock_t *tempoInicio, long *totalIteracoes)
{
    long varTemp, contSwap = 0, contInter = 0, contIteracoes = 0;
    int bolBreak;
    *tempoInicio = clock();
    for (int i = 0; i < tamVet; i++)
    {
        bolBreak = 0;
        contIteracoes++;
        for (int j = 0; j < tamVet - 1; j++)
        {
            if (vetBubble[j] > vetBubble[j + 1])
            {
                varTemp = vetBubble[j];
                vetBubble[j] = vetBubble[j + 1];
                vetBubble[j + 1] = varTemp;
                contSwap++;
                contInter++;
                bolBreak = 1;
            }
            contInter++;
        }

        if (bolBreak == 0)
        {
            break;
        }
    }
    *tempoInicio = clock() - *tempoInicio;
    *totalIteracoes = contIteracoes;
    *totalSwap = contSwap;
    *totalInter = contInter;
}

// MAIN //
int main()
{
    srand(10);
    clock_t tempoInicio;
    int vet[10];
    long totalSwap, totalComp, totalnter;
    int tamVet = 10;
    // listaOrdenadaDecrescente(vet, tamVet);
    listaOrdenada(vet, tamVet);
    // listaParcialmenteOrdenada75(vet, tamVet);
    //  createRandomList(vet, tamVet);
    //  listaParcialmenteOrdenada50(vet, tamVet);
    bubbleSort(vet, tamVet, &totalSwap, &totalComp, &tempoInicio, &totalnter);
    for (int i = 0; i < tamVet; i++)
    {
        printf("%d\n", vet[i]);
    }

    printf("Tempo em milisegundos: %f\n", (1000.0 * tempoInicio) / CLOCKS_PER_SEC);
    printf("Numero de trocas: %d\n", totalSwap);
    printf("Numero de comparações: %d\n", totalComp);
    printf("Numero de interacoes: %d\n", totalnter);

    // bubbleSort(vet);

    return 0;
}