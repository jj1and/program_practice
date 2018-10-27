#include<iostream>
using namespace std;

int diff(int a, int b){
    int c;
    c = a-b;
    return c;
}

double diff(double a, double b){
    double c;
    c = a-b;
    return c;
}

int main(){
    int result_i;
    double result_f;
    
    int (*diff)()

    result_i = diff(2, 1);
    result_f = diff(2.0, 1.0);
    cout << "int: " << &result_i << endl;
    cout << "double: " << &result_f << endl; 
}