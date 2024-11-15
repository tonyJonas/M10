#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

#define N 100000000 // vetor

int main() {
    int i;
    int *arr;
    long long soma_serial = 0;
    long long soma_parallel = 0;
    struct timeval start, end;
    double elapsed_time_serial, elapsed_time_parallel;
    int num_threads_array[] = {1, 2, 4, 8, 16, 20}; // Número de threads
    int num_tests = sizeof(num_threads_array) / sizeof(num_threads_array[0]);

    arr = (int *) malloc(N * sizeof(int));

    // Seed para reprodutibvilidade
    srand(42);

    // Inicializar o vetor com valores aleatórios entre 0 e 99
    for (i = 0; i < N; i++) {
        arr[i] = rand() % 100;
    }

    // Versão serializada do algoritmo
    gettimeofday(&start, NULL);
    for (i = 0; i < N; i++) {
        soma_serial += arr[i];
    }
    gettimeofday(&end, NULL);
    elapsed_time_serial = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
    printf("Versão Serial:\n");
    printf("Tempo de execução: %f segundos\n", elapsed_time_serial);
    printf("Soma dos elementos do vetor: %lld\n\n", soma_serial);

    // Versão paralelizada do algoritmo
    for (int t = 0; t < num_tests; t++) {
        int num_threads = num_threads_array[t];
        soma_parallel = 0;  // Reinicia a soma para cada teste

        // Definir o número de threads
        omp_set_num_threads(num_threads);

        // Obter o tempo inicial
        gettimeofday(&start, NULL);

        // Seção paralelizada: soma dos elementos do vetor
        #pragma omp parallel for reduction(+:soma_parallel)
        for (i = 0; i < N; i++) {
            soma_parallel += arr[i];
        }

        // Obter o tempo final
        gettimeofday(&end, NULL);
        elapsed_time_parallel = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

        printf("Versão Paralela com %d threads:\n", num_threads);
        printf("Tempo de execução: %f segundos\n", elapsed_time_parallel);
        printf("Soma dos elementos do vetor: %lld\n\n", soma_parallel);
    }

    free(arr);

    return 0;
}