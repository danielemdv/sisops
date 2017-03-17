#include <omp.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) { /* sequential code */


int i, N=7,ans, numThreads = omp_get_max_threads();

int ress[numThreads]; //Array to store pre answers (before joining)...
//Initialize the array to 1s
for(i = 0; i < numThreads; i++){
  ress[i] = 1;
}

printf("DEBUG NUM THREADS %d", numThreads);


          /* sequential code */
#pragma omp parallel for
for(i=1;i<N;i++) {
  //Note the for starts at 1 cause we're going to ignore 0 in the multiplication.

    ress[omp_get_thread_num()] = ress[omp_get_thread_num()]*(i+1); //Calculates the products and stores them seperately
    printf("Calculando entrada %d\n",i);
    //sleep(1);
}

printf("Integrating answer");

ans = 1;
for(i = 0; i < numThreads; i++){
  //note for starts at 1
  ans = ans * ress[i];
}

printf("\nEl resultado es! %d\n", ans);

return 0;

}
