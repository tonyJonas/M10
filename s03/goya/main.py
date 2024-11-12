import threading

# Função de soma da lista
def soma_parcial(lista, resultados, indice):
    # Calcula a soma parcial da lista fornecida
    soma = sum(lista)
    # Imprime a soma calculada pela thread atual
    print(f"Thread {indice}: soma da sublista {lista} = {soma}")
    # Armazena o resultado na posição correta da lista de resultados
    resultados[indice] = soma

# Função para executar a soma
def executar_soma(lista_numeros):
    print(f"\nExecutando soma com 2 threads e lista: {lista_numeros}")
    num_threads = 2 

    # Dividindo a lista em duas partes
    meio = len(lista_numeros) // num_threads
    primeira_parte = lista_numeros[:meio]
    segunda_parte = lista_numeros[meio:]

    threads = []
    resultados = [0] * num_threads  # Inicializando a lista de resultados com zeros

    # Criando e inician a primeira thread
    print(f"Thread 0: processando sublista {primeira_parte}")
    thread1 = threading.Thread(target=soma_parcial, args=(primeira_parte, resultados, 0))
    threads.append(thread1)
    thread1.start()

    # Cria e inicia a segunda thread
    print(f"Thread 1: processando sublista {segunda_parte}")
    thread2 = threading.Thread(target=soma_parcial, args=(segunda_parte, resultados, 1))
    threads.append(thread2)
    thread2.start()

    # Aguarda ambas as threads terminarem
    for thread in threads:
        thread.join()

    # Soma os resultados parciais para obter a soma total
    soma_total = sum(resultados)
    # Imprime os resultados parciais e a soma total
    print(f"Resultado parcial das threads: {resultados}")
    print(f"Soma total: {soma_total}")


# TESTE 1
lista_numeros1 = [1, 2, 3, 4, 5, 6]
executar_soma(lista_numeros1)

# TESTE 2
lista_numeros2 = [-10, -20, 30, 40, -50, 60]
executar_soma(lista_numeros2)

# TESTE 3
lista_numeros3 = list(range(1, 101)) 
executar_soma(lista_numeros3)

