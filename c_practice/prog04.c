#include <stdio.h>
#include <math.h>

main(){
  float x1[3], x2[3], length;
  int i;
  printf("input x1_array (x1, y1, z1):" );
  scanf("%f %f %f", &x1[0], &x1[1], &x1[2] );
  printf("input x2_array (x2, y2, z2):" );
  scanf("%f %f %f", &x2[0], &x2[1], &x2[2] );
  for (i = 0; i < 3; i++) {
    length = length + sqrt(pow(x1[i]-x2[i], 2));
  }
  printf("The length between points x1&x2 = %f\n", length);
}
