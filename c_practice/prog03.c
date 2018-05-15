#include <stdio.h>
int main(void){
  float num1, num2, num3;
  printf("input number 1: ");
  scanf("%f", &num1 );
  printf("input number 2: ");
  scanf("%f", &num2 );

  if (num2==0){
    printf("You cannot divide by 0\n");
  }
  else{
    num3 = num1/num2;
    printf("number 1/number2 = %f\n", num3 );
  }
  return 0;
}
