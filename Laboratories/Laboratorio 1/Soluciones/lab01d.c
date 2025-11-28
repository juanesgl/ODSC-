#include<stdlib.h>
#include<stdio.h>
#define MAX 2000

void read_vector(int v[], int n){
  int i;
  for (i = 0; i < n; i++){
    scanf("%d", &v[i]);
  }
}

int vector_sum(int v[], int n){

 int i, suma = 0;
 for (i = 0; i < n; i++){
     suma += v[i];
 }
 return suma;
}


int main(){

  int tc, i, n, result;
  int v[MAX];

  scanf("%d", &tc);
  for (i = 0; i < tc; i++){
      scanf("%d", &n);
      read_vector(v,n);
      result = vector_sum(v,n);
      printf("%d\n", result);
  }
  return 0;
}
