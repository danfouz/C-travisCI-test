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

  for (n=2;n<=64;n*=2){
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
int main(){
	test1();
}

