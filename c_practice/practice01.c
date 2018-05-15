#include<stdio.h>
main(){
  int flag = 0;
  do{
    int select_num;
    printf("\t好きなゲームメーカーに対応する数字を選んでね\n ");
    printf("\tMarvelous Inc.     \t: 1\n");
    printf("\tNintendo Co., Ltd. \t: 2\n");
    printf("\tFromSoftware, Inc. \t: 3\n");
    printf("\tSQUARE ENIX CO., LTD. \t: 4\n");
    printf("\tGungHo Online Entertainment, Inc. \t: 5\n");
    scanf("%d", &select_num );
    switch (select_num) {
      case 2:
      printf("\tNintendo Switch は人気ですよね\n");
      flag = 1;
      break;
      default :
      printf("\n \t察してください\n \n");
      break;
    }
  }while (flag==0);
}
