// TONY - Problema da Busca

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <sys/time.h>

// Tamanhos diferentes de N para teste
#define NUM_TESTS 3
long long N_values[NUM_TESTS] = {10000000, 100000000, 1100000000};

int main()
{
    int i, t, test;
    int *arr;
    int max_serial = 0;
    int max_parallel = 0;
    struct timeval start, end;
    double elapsed_time_serial, elapsed_time_parallel;
    int num_threads_array[] = {1, 2, 4, 8, 16}; // Número de threads
    int num_thread_tests = sizeof(num_threads_array) / sizeof(num_threads_array[0]);

    // Iterar por diferentes valores de N
    for (test = 0; test < NUM_TESTS; test++)
    {
        long long N = N_values[test]; // Define o tamanho atual do vetor
        printf("=== Teste com N = %lld ===\n", N);

        arr = (int *)malloc(N * sizeof(int));

        // Seed para reprodutibilidade
        srand(42);

        // Inicializar o vetor com valores aleatórios entre 0 e N
        for (i = 0; i < N; i++)
        {
            arr[i] = rand() * rand() % (N + 1);
        }

        // Versão serial do algoritmo
        gettimeofday(&start, NULL);
        max_serial = 0;
        for (i = 0; i < N; i++)
        {
            if (arr[i] > max_serial)
            {
                max_serial = arr[i];
            }
        }
        gettimeofday(&end, NULL);
        elapsed_time_serial = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;
        printf("Versão Serial:\n");
        printf("Tempo de execução: %f segundos\n", elapsed_time_serial);
        printf("Maior número no vetor: %d\n\n", max_serial);

        // Versão paralelizada do algoritmo
        for (t = 0; t < num_thread_tests; t++)
        {
            int num_threads = num_threads_array[t];
            max_parallel = 0; // Reinicia o valor máximo para cada teste

            // Definir o número de threads
            omp_set_num_threads(num_threads);

            // Obter o tempo inicial
            gettimeofday(&start, NULL);

            // Seção paralela: encontrar o maior número
            #pragma omp parallel
            {
                int local_max = 0; // Cada thread calcula seu máximo local
                #pragma omp for
                for (int i = 0; i < N; i++)
                {
                    if (arr[i] > local_max)
                    {
                        local_max = arr[i];
                    }
                }

                // Combinação dos máximos locais em um único valor global
                #pragma omp critical
                {
                    if (local_max > max_parallel)
                    {
                        max_parallel = local_max;
                    }
                }
            }

            // Obter o tempo final
            gettimeofday(&end, NULL);
            elapsed_time_parallel = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1e6;

            printf("Versão Paralela com %d threads:\n", num_threads);
            printf("Tempo de execução: %f segundos\n", elapsed_time_parallel);
            printf("Maior número no vetor: %d\n\n", max_parallel);
        }

        free(arr);
    }

    return 0;
}
