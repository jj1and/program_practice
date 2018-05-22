#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
  float x,y;
  double u,v;
  char a,b;

  x=M_PI;
  y = x*x;
  u = M_PI;
  v = u*u;
  a = 'a';
  b = 'B';

  printf("float;  \txの値:%f,     \tアドレス:%u, バイト数:%d\n", x, &x, sizeof(x) );
  printf("float;  \tyの値:%f, \tアドレス:%u, バイト数:%d\n", y, &y, sizeof(y) );
  printf("double; \tuの値:%f,     \tアドレス:%u, バイト数:%d\n", u, &u, sizeof(u) );
  printf("double; \tvの値:%f, \tアドレス:%u, バイト数:%d\n", v, &v, sizeof(v) );
  printf("char;   \taの値:%c,     \t\tアドレス:%u, バイト数:%d\n", a, &a, sizeof(a) );
  printf("char;   \tbの値:%c,     \t\tアドレス:%u, バイト数:%d\n", b, &b, sizeof(b) );

  return 0;
}
