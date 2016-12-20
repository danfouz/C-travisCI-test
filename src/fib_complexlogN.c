#include <stdio.h>
#include <sys/time.h>
#include <math.h>


double microsegundos() {
  struct timeval t;
  if (gettimeofday(&t, NULL) < 0)
    return 0.0;
  return(t.tv_usec + t.tv_sec *1000000.0);
}



int fib3(int n){
int i,j,k,h,t;
  i=1; k=0; j=0; h=1;
  while (n>0) {
    if ((n % 2) != 0) {
      t=j*h;
      j=(i*h) + (j*k) + t;
      i=(i*k) + t;
    }
    t=h*h;
    h=(2*k*h) + t;
    k=(k*k) + t ;
    n= n/2;
  }
  return j;
}




