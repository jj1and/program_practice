#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int init_prime_check(int);
int *make_prime_array(int);
void print_prime_num(int, int *);

int main(void){
    int *prime_array;
    int num = 500;
    printf("Nまでの素数の数を確かめたい！\n");
    printf("N :");
    scanf("%d",&num);
    print_prime_num(num, make_prime_array(num));

    return 0;
}



int init_prime_check(int n){
    int check_num;
    int r;
    int check=1;
    check_num = (int)pow(n, 0.5);

    
    for(int i = 2; i <= check_num; i++){
        r = n%i;
        if(r==0){
            check = 0;
            break;
        }
    }
    return check;
    
}

int *make_prime_array(int n){
    int check;
    int check_max;
    int *prime_array;
    check_max = (int)pow(n, 0.5);
    prime_array = (int *)malloc(sizeof(int)*(check_max-1));
    
    for(int i =2 ; i <= check_max; i++){
        if(init_prime_check(i)==1){
            prime_array[i-2]=i;
        }
        else{
            prime_array[i-2]=0;
        }
    }
    return prime_array;
    free(prime_array);

}

void print_prime_num(int n, int *prime_array){
    int r=0;
    int cnt=0;
    for(int m = 2; m <= n; m++){
        for(int i = 0; i < pow(n, 0.5)-1; i++){
            if(prime_array[i]==0){
                continue;
            }
            else if(m==prime_array[i]){
                printf("%d \n",m);
                r=0;
                cnt++;
                break;
            }
            r = m%prime_array[i];
            if(r==0){
                break;
            }
        }
        if(r!=0){
            printf("%d \n", m);
            cnt++;
        }
    }
    printf("%dまでの素数の数は%d個です。\n",n,cnt);
    
    
}


