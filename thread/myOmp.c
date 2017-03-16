#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[]) {


  #pragma omp parallel
  {

    int ID = omp_get_thread_num();

    printf("Hello World!! %d\n", ID);
  }

  return 0;
}
