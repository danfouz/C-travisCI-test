#include <stdio.h>
#include <sys/time.h>
#include <math.h>





//Algoritmos implementados
int fib1(int n){

  if (n<2)
    return n;
  else
    return fib1(n-1) + fib1(n-2);
}
int main()
{
	fib1(40);
}


