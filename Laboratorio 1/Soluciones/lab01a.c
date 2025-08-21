
#include<stdio.h>
#include<stdlib.h>


int main(){

 int test_cases, x, y, i;

 scanf("%d", &test_cases);

 for (i = 0; i < test_cases;i++){
   scanf("%d", &x);
   scanf("%d", &y);
   printf("%d\n", x+y);

 }
 return 0;
}
