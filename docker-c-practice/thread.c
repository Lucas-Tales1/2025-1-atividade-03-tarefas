// Exemplo de uso de threads POSIX em C no Linux
// Compilar com: gcc exemplo.c -o exemplo -lpthread

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5

// Cada thread vai executar esta função
void *print_hello(void *threadid)
{
    printf("%ld: Hello World!\n", (long) threadid);
    sleep(5);
    printf("%ld: Bye bye World!\n", (long) threadid);
    pthread_exit(NULL); // Encerra esta thread
}

// Thread "main" (vai criar as demais threads)
int main(int argc, char *argv[])
{
    pthread_t thread[NUM_THREADS];
    long status, i;

    // Cria as demais threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("Creating thread %ld\n", i);
        status = pthread_create(&thread[i], NULL, print_hello, (void *) i);

        if (status) // Ocorreu um erro
        {
            perror("pthread_create");
            exit(-1);
        }
    }

    // Encerra a thread "main"
    pthread_exit(NULL);
}
