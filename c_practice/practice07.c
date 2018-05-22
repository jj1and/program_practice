#include <stdio.h>
#define ELE_NUM 7

int main(int argc, char const *argv[]) {
  int i;
  double result;
  double sum_func(double *);
  double *make_array(void);
  result = sum_func(make_array());
  printf("総和は %f です。\n", result);

  return 0;
}

double *make_array(void){
  int i;
  double hh[ELE_NUM]={0};
  double *phh;
  for (i = 0; i < ELE_NUM; i++) {
    printf("%d要素のdouble型配列の%d要素目を入力してください\n", ELE_NUM, i+1);
    scanf("%lf", &hh[i]);
  }
  phh = hh;
  return phh;
}

double sum_func(double *phh){
  int i;
  double sum;
  for (i = 0; i < ELE_NUM; i++) {
    sum = sum + phh[i];
  }
  return sum;
}
