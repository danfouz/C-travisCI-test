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

//Pruebas de medicion de tiempos sobre los Algoritmos
void test1(){
int n,j,umbral=500,repeticiones=1000;char flag;
double ajustada,sobrestimada,subestimada,t1,t2,ta,tb,tu,t;
  printf("\nTEST 1");
  printf("\n%5s%15s%15s%13s%15s","n","t(n)","Subestimada","Ajustada","Sobrestimada");
  printf("\n%35s%13s%13s\n","t(n)/1,1^n","t(n)/1,6^n","t(n)/2^n");
  for(j=0;j<70;j++){
    printf("-");
  }
  printf("\n");

  for (n=2;n<=32;n*=2){
    flag=' ';
    t1=microsegundos();
    fib1(n);
    t2=microsegundos();
    t=t2-t1;
    if (t < umbral) {
      flag='*';
      int k;
      ta=microsegundos();
      for (k=0;k<repeticiones;k++){
        fib1(n);
      }
      tb=microsegundos();
      tu=tb-ta;
      ta=microsegundos();
      for (k=0;k<repeticiones;k++){
      }
      tb=microsegundos();
      t=tb-ta;
      t=(tu-t)/repeticiones;
    }
    ajustada=t/pow(((1+ sqrt(5))/2),n);
    sobrestimada=t/pow(2,n);
    subestimada=t/pow(1.1,n);
    printf("%5d%14.4f%3c%13.6f%13.6f%13.6f\n",n,t,flag,subestimada,ajustada,sobrestimada );
  }
}

void test2(){
int n,j,umbral=500,repeticiones=1000;char flag;
double ajustada,sobrestimada,subestimada,t1,t2,ta,tb,tu,t;
  printf("\nTEST 2");
  printf("\n%10s%15s%15s%13s%14s","n","t(n)","Subestimada","Ajustada","Sobrestimada");
  printf("\n%40s%13s%15s\n","t(n)/n^0.8","t(n)/n","t(n)/n*log(n)");
  for(j=0;j<70;j++){
    printf("-");
  }
  printf("\n");

  for (n=1000;n<=10000000;n*=10){
    t1=microsegundos();
    flag=' '; fib2(n);
    t2=microsegundos();
    t=t2-t1;
    if (t < umbral) {
      flag='*';
      int k;
      ta=microsegundos();
      for (k=0;k<repeticiones;k++){
        fib2(n);
      }
      tb=microsegundos();
      tu=tb-ta;
      ta=microsegundos();
      for (k=0;k<repeticiones;k++){
      }
      tb=microsegundos();
      t=tb-ta;
      t=(tu-t)/repeticiones; 
    }
    ajustada=t/n;
    sobrestimada=t/(n*(log(n)));
    subestimada=t/pow(n,0.8);
    printf("%10d%14.4f%3c%13.6f%13.6f%13.6f\n",n,t,flag,subestimada,ajustada,sobrestimada );
  }
}

void test3(){
int n,j,umbral=500,repeticiones=1000;char flag;
double ajustada,sobrestimada,subestimada,t1,t2,ta,tb,tu,t;
  printf("\nTEST 3");
  printf("\n%10s%15s%15s%13s%14s","n","t(n)","Subestimada","Ajustada","Sobrestimada");
  printf("\n%42s%12s%13s\n","t(n)/sqrt(log(n))","t(n)/log n","t(n)/n^0.5");
  for(j=0;j<70;j++){
    printf("-");
  }
  printf("\n");

  for (n=1000;n<=10000000;n*=10){
    t1=microsegundos();
    flag=' '; fib3(n);
    t2=microsegundos();
    t=t2-t1;
    if (t < umbral) {
      flag='*'; 
      int k;
      ta=microsegundos();
      for (k=0;k<repeticiones;k++){
        fib3(n);
      }
      tb=microsegundos();
      tu=tb-ta;
      ta=microsegundos();
      for (k=0;k<repeticiones;k++){
      }
      tb=microsegundos();
      t=tb-ta;
      t=(tu-t)/repeticiones;
    }
    ajustada=t/log(n); 
    sobrestimada=t/pow(n,0.5); 
    subestimada=t/sqrt(log(n));
    printf("%10d%14.4f%3c%13.6f%13.6f%13.6f\n",n,t,flag,subestimada,ajustada,sobrestimada );
  }
}

void procesar(){
int i;
  for(i=0;i<3;i++){
    test1();
  }
  for(i=0;i<3;i++){
    test2();
  }
  for(i=0;i<3;i++){
    test3();
  }
}
int main(){
test();
getchar();
procesar();
}











