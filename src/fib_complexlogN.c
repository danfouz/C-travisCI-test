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


