#include <stdio.h>
main(){
  int num1, num2;
  printf("input number 1: ");
  scanf("%d", &num1 );
  printf("input number 2: ");
  scanf("%d", &num2 );

  if (num2!=0) {
    printf("number 1/number2 = %d\n", num1/num2 );
  }
}
