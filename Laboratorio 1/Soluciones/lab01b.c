#include<stdlib.h>
#include<stdio.h>



int main(){


 int tc, i;
 float x, y;

 scanf("%d", &tc);
 
 for (i = 0; i < tc; i++){

 scanf("%f", &x);
 scanf("%f", &y);

 if (x > y){

 printf("%f\n", x);

 }else if (y > x){
   printf("%f\n", y);
 }

}
return 0;
}
