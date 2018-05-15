#include <stdio.h>
#include <math.h>

main(){
  double tmp_num , buff = 0;
  int flag = 0;
  int result = 0;
  do {
    printf("\t整数値を入力してください\n");
    printf("\t終了する場合は0を入力してください\n");
    scanf("%lf", &tmp_num);
    if (tmp_num==0) {
      printf("\t計算を終了します\n");
      flag=1;
    }
    else if (fabs(buff+tmp_num)>=2147483647) {
      printf("\t合計値が整数型の範囲を越えます\n");
      printf("\t直前の入力までの結果を表示します\n");
      flag=1;
    }
    else if (tmp_num-(int)tmp_num!=0) {
      printf("\t小数ではなく整数値を入力してください\n");
      printf("\tこの入力は合計されません\n \n");
    }
    else {
      buff = buff + tmp_num;
    }
  } while(flag==0);
  result = buff;
  printf("\t合計は%dです\n", result);
}
