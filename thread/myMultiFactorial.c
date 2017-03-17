#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "gmp.h"

int main(int argc, char *argv[]) { /* sequential code */


int i, N,ans, num_cores = omp_get_num_procs(), numThreads = omp_get_max_threads(), thread;
mpz_t *res, factorial;

if(argc < 2) fprintf(stderr, "Uso %s tope \n", argv[0]);

N = atoi(argv [1]);

res = (mpz_t*)malloc(sizeof(mpz_t)*num_cores);

//initialize our answer variable to 1
mpz_init_set_ui(factorial, 1);

//Initialize the array to 1s
for(i = 0; i < num_cores; i++){
  mpz_init_set_ui(res[i], 1);
}

printf("DEBUG NUM THREADS %d, NUM CORES %d", numThreads, num_cores);


          /* sequential code */
#pragma omp parallel for
for(i=1;i<=N;i++) {
  //Note the for starts at 1 cause we're going to ignore 0 in the multiplication.
	thread = omp_get_thread_num();
    mpz_mul_ui(res[thread], res[thread],i); //res[thread] *= i; //Calculates the products and stores them seperately
    printf("Calculando entrada %d\n",i);
    //sleep(1);
}

printf("Integrating answer");

ans = 1;
for(i = 0; i < num_cores; i++){
  //note for starts at 1
	mpz_mul_ui(factorial,factorial,i); //was: ans = ans * res[i];
  
}

printf("\nEl resultado es!\n");

mpz_out_str(stdout, 10, factorial);

mpz_clear(factorial);
for(i = 0; i < num_cores; i++){
	mpz_clear (res[i]);
}

return 0;

}
