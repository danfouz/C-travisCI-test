#include <stdio.h>
#include <sys/time.h>
#include <math.h>




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
int main()
{
	fib3(1000000000);
}





