#include <stdio.h>

main(){
  int b,a;
  void exchange(int, int);
  printf("Input integers a & b:");
  scanf("%d %d", &a, &b);
  printf("a=%d, b=%d\n", a, b);
  exchange(a, b);
  printf("a=%d, b=%d\n", a, b);
}
void exchange(int a, int b){
  int c;
  c = a;
  a = b;
  b = c;
}
