#include <omp.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) { /* sequential code */

int res = 1;
#pragma omp threadprivate(res)

int i, N=7,ans = 1;



printf("Num maximo de threads que se pueden crear: %d",omp_get_max_threads());



#pragma omp parallel for
for(i=1;i<N;i++) {
  //Note the for starts at 1 cause we're going to ignore 0 in the multiplication.

    res = res *i*(i+1); //ir acumulando el resultado de los 'factoriales parciales' en res que es de TLS para cada thread.

    printf("Calculando entrada %d\n",i);
}

printf("Integrating answer");

#pragma omp parallel
{
	#pragma omp atomic
	{
		ans	= ans * res;
	}
	
}


printf("\nEl resultado es! %d\n", ans);

return 0;

}
