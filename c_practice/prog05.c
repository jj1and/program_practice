#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main(){
  int face, roll, freqency[7]={0};
  srand(time(NULL));
  for (roll = 1; roll <=6000; roll++) {
    face=rand() %6+1;
    ++freqency[face];
  }
  for (face = 1; face <=6; face++) {
    printf("%4d%10d\n",face, freqency[face] );
  }
  return 0;
}
