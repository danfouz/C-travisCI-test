/*
Primera práctica de algoritmos 

Fecha: 29 de septiembre del 2014

Autores:
    Ludovic Calvo dos Santos G 4.1.2
	Daniel Moledo Garcia G 4.1.2

Maquina del laboratorio   
    -
    -

Unidades:
    us : microsegundos
*/

/*
PREGUNTAS:

-COTA AJUSTADA TEST3 LOG N ?
-


*/
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

//Validacion sobre los Algoritmos
void test(){
  int n,i;
  n=10;
  printf("\nPRUEBA ALGORITMOS FIBONACCI\n");
  printf("%18s%16s%15s%15s\n","n","fib1","fib2","fib3");
  for(i=1;i<n;i++){
    printf("%18d%15d%15d%15d\n",i,fib1(i),fib2(i),fib3(i));
  }
}


int main(){
test();
}











