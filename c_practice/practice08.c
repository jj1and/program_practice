#include <stdio.h>
#define CHAR_NUM 100

int main(int argc, char const *argv[]) {
  int *pst_prop;
  char *input_string(void);
  int *check_strlen(char *);
  void analy_func(int *);

  pst_prop = check_strlen(input_string());
  analy_func(pst_prop);

  return 0;
}

char *input_string(void){
  char str[2*CHAR_NUM+1]={0};
  char *pstr;
  int i;
  printf("適当に100文字以内で入力してください\n");
  fgets(str, 2*CHAR_NUM+2, stdin);
  pstr = str;
  return pstr;
}

int *check_strlen(char *pstr){
  int i = 0;
  int *pst_prop;
  int stlen = 0;
  int spnum = 0;
  for (i = 0; i < 2*CHAR_NUM+1; i++) {
    if (pstr[i]=='\n') {
      break;
    }
    else if (pstr[i]==' '){
      spnum++;
      continue;
    }
    stlen++;
  }
  int st_prop[2]={stlen, spnum};
  pst_prop = st_prop;
  return pst_prop;
}

void analy_func(int *pst_prop){
  if(pst_prop[0]>101){
    printf("100文字越えてますよ\n");
    while (getchar()!='\n');
  }
  else if(pst_prop[1]>100){
    printf("そんなにスペースばっかり入力して大丈夫ですか？\n");
  }
  else{
    printf("文字数：%d字, 空白文字：%d字\n", pst_prop[0], pst_prop[1]);
  }
}
