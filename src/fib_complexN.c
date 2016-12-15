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




