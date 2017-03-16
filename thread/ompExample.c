#include <omp.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) { /* sequential code */
int i, N=400, c[400], a[400], b[400];

for (i=0;i<N;i++) {
a[i]=i*2;
b[i]=i*3;
}

#pragma omp parallel
{
    printf("I am a parallel region.\n");
}
          /* sequential code */
#pragma omp parallel for
for(i=0;i<N;i++) {
     c[i] = a[i] + b[i];
     printf("Calculando c[%d]\n",i);
     sleep(1);
}

for(i=0;i<N;i++) {
     printf("Vector c[%d]=%d\n",i,c[i]);
}
          return 0;
}
