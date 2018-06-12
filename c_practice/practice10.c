#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_DIM 10

float distance(int, float *, float *);
float *get_point(int);
float **set_points(void);

int main(void){


    float **pp;
    float *point1, *point2, *dim;
    float dist;
    
    pp = set_points();
    point1 = pp[0];
    point2 = pp[1];
    dim = pp[2];

    dist = distance((int)*dim, point1, point2);
    printf("二点間の距離は %.4f です。\n", dist);

    return 0;
}

float distance(int n, float *point1_array, float *point2_array){
    float sqr_sum = 0.0;
    float dist;
    for(int i = 0; i < n; i++){
        sqr_sum = sqr_sum + pow((point1_array[i]-point2_array[i]), 2);
    }
    dist = sqrt(sqr_sum);
    return dist;
}

float *get_point(int dim){
    int cnt;
    int flag;
    char p[8*MAX_DIM-1];
    char *ptr;
    float *point;
    point = (float *)malloc(sizeof(float)*dim);
    do{
        printf("座標を入力してください。有効桁数は5桁です。\n");
        printf("3次元の例：\"1.0, 2.0, 3.0\" \n");
        fgets(p, 6*MAX_DIM, stdin);
        ptr = strtok(p,", ");
        point[0] = strtof(ptr, NULL);
        cnt = 1;
        while(ptr!=NULL){
            ptr = strtok(NULL, ", ");
            if(ptr!=NULL){
                if(cnt<dim){
                    point[cnt] = strtof(ptr, NULL);   
                }
                cnt++;
            }
        }
        if(cnt==dim){
            flag = 0;
        }
        else{
            printf("きちんと入力してください\n");
            flag = 1;
        }
        while(getchar()!='\n');
    }while(flag==1);
    return point;
    free(point);
}

float **set_points(void){
    int flag;
    float dim;
    char dim_char[(int)(MAX_DIM/10)+1];
    float **pp;
    float *pt_array[3];
    do{
        printf("次元を入力してください(最大%d次元)\n", MAX_DIM);
        fgets(dim_char, (int)(MAX_DIM/10)+2, stdin);
        dim = strtof(dim_char, NULL);
        pt_array[2] = &dim;
        if((dim!=0.0)&&(dim<=10)){
            flag = 0;
        }
        else{
            printf("きちんと入力してください\n");
            flag = 1;
        }
        while(getchar()!='\n');
    }while(flag==1);
    printf("一つ目の点について\n");
    pt_array[0] = get_point((int)dim);
    printf("二つ目の点について\n");
    pt_array[1] = get_point((int)dim);
    pp = pt_array;
    return pp;
    
}
