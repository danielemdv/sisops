#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>

char *pname = NULL;

void err_sys(char *fmt, ...);

int main(int argc, char *argv[])
{
    int pid, pid2, fd[2];
    int status, ret;
    char *argv_hijos[10];

    pname=argv[0];

    if (pipe(fd)<0) 
	err_sys("can't create pipes");

    pid = fork();
    if (pid == 0) {
        close(fd[1]);
        ret = dup2(fd[0],0);
        if (ret < 0) err_sys("dup2");
        argv_hijos[0] = "more";  argv_hijos[1] = NULL;
        execvp("more", argv_hijos);
    } 
    /* Create another child process for ls */
    pid2 = fork();
    if (pid2 == 0) {
        ret = dup2(fd[1],1);
        if (ret < 0) err_sys("dup2");
        argv_hijos[0] = "cat";    argv_hijos[1] = "mainshmserv.c";   
        argv_hijos[2] = NULL;
        execvp("cat", argv_hijos);
    }

    /* close parent's pipes */
    close(fd[0]);
    close(fd[1]);

    // wait for the more process to finish
    waitpid(pid, &status, 0);

    printf("Done! %d [%d]\n",pid,status);
    return 0;
}

