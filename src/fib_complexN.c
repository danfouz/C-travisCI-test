#include <stdio.h>
#include <sys/time.h>
#include <math.h>

double microsegundos() {
  struct timeval t;
  if (gettimeofday(&t, NULL) < 0)
    return 0.0;
  return(t.tv_usec + t.tv_sec *1000000.0);
}


int fib2(int n){
  int i,j,k;
  i=1;
  j=0;
  for (k=0;k<n;k++){
    j=i+j;
    i=j-i;
  }
  return j;
}




