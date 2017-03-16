#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {

int fd = open("salida.txt", O_WRONLY|O_CREAT, 0666);

dup2(fd, 1);
close(fd);

printf("El muro de Trump!\n");

return 0;

}
