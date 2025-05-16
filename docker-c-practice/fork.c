#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    int pid; // Identificador de processo

    pid = fork(); // Replicação do processo

    if (pid < 0) // Verifica se o fork funcionou
    {
        perror("Erro: fork falhou");
        exit(-1); // Encerra este processo
    }
    else if (pid > 0) // Processo pai
    {
        wait(0); // Espera o processo filho terminar
    }
    else // Processo filho
    {
        // Carrega outro código binário para executar
        execve("/bin/date", argv, envp);

        perror("Erro: execve falhou"); // Se execve falhar
    }

    printf("Tchau!\n"); // Este código será executado apenas pelo processo pai
    exit(0); // Encerra este processo
}
