#include <stdio.h>
#include <string.h>
#define NUM 20
#define LIMIT 20

main() {
  int i;
  int flag=0;
  int stlen;
  char string[NUM+1]={0};
  do {
    printf("適当に20文字入力してください\n");
    /*scanfだと文字数制限がやりにくいのでコメントアウト。代わりにfgetsを使っています。*/
    //scanf("%21s", string);
    //fgets(string, n, sdtin);は標準入力のn-1文字まで取得する
    fgets(string , NUM+2, stdin);
    //改行文字を除くのでstlen-1
    stlen = strlen(string)-1;
    //fgetsでは入力の最終文字は改行文字になる
    //20文字をオーバーすると21文字目が改行文字にならない
    if (string[stlen]!='\n') {
      printf("文字数が20文字を超えています。 \n", stlen);
      printf("20文字って言いいましたよね?\n");
      while(getchar()!='\n');
      printf("もう一度");
    }
    else{
      flag = 1;
    }
  } while(flag==0);
  printf("入力 : %s", string);
  printf("受け付けました\n");
  printf("文字列を反転します。\n");
  for (i = 1; i <= stlen; i++) {
    printf("%c",string[stlen-i]);
  }
  printf("\n");

}
