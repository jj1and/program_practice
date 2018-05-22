#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRY_NUM 36000

main(){
  int sum_freq[13]={0};
  int face1_freq[7]={0};
  int face2_freq[7]={0};
  int i, face1, face2;
  for (i = 0; i < TRY_NUM; i++) {
    face1 = rand()%6+1;
    face2 = rand()%6+1;
    ++face1_freq[face1];
    ++face2_freq[face2];
    ++sum_freq[face1+face2];
  }

  printf("サイコロの和\n");
  for (i = 2; i <=12; i++) {
    printf("%4d%10d\n", i, sum_freq[i] );
  }

  printf("サイコロ1\n");
  for (i = 1; i <=6; i++) {
    printf("%4d%10d\n", i, face1_freq[i] );
  }

  printf("サイコロ2\n");
  for (i = 1; i <=6; i++) {
    printf("%4d%10d\n", i, face2_freq[i] );
  }
}
