#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *pname = NULL;

int main(int argc, char *argv[])
{
    int pid, pidgrp;
    pname=argv[0];

    if (fork() != 0) 
	exit(0);

    /* El hijo */
    pidgrp = setpgrp();
    pid = getpid();
    sleep(60);
    printf("Terminó el servidor pid =% d\n", pid);

    return 0;
}

