#include <stdio.h>

main(){
  int a[2], *pa, *pb;
  void exchange(int *, int *);
  printf("Input integers a & b:");
  scanf("%d %d", &a[0], &a[1]);
  printf("a=%d, address=%d\n", a[0], &a[0]);
  printf("b=%d, address=%d\n", a[1], &a[1]);
  pa = &a[0];
  pb = &a[1];

  exchange(pa, pb);
  printf("a=%d, b=%d\n", a[0], a[1]);
}
void exchange(int *pa, int *pb){
  int c;
  c = *pa;
  *pa = *pb;
  *pb = c;
}
