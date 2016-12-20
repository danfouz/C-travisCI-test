#include <stdio.h>
#include <sys/time.h>
#include <math.h>

double microsegundos() {
  struct timeval t;
  if (gettimeofday(&t, NULL) < 0)
    return 0.0;
  return(t.tv_usec + t.tv_sec *1000000.0);
}




//Algoritmos implementados
int fib1(int n){
  if (n<2)
    return n;
  else
    return fib1(n-1) + fib1(n-2);
}


