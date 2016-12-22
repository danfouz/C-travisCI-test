#include <stdio.h>
#include <sys/time.h>
#include <math.h>


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

int main()
{
	fib2(100000000);
}


