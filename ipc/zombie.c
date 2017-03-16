#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

char *pname = NULL;

int main(int argc, char *argv[])
{
    int pid;
    pname=argv[0];

    if (fork() != 0) {
	sleep(20); 
        printf("Despert√ el padre, limpiando al zombie\n");
        wait((int*)0);
	exit(0);
    }

    /* El hijo */
    pid = getpid();
    printf("Termin√≥el hijo pid =% d\n", pid);

    return 0;
}

