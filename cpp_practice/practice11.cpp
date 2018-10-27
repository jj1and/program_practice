#include<iostream>
using namespace std;
class coord{
    private:    
        int x,y;
    public:
        coord(){x=0; y=0;};
        coord(int i, int j){ x=i; y=j;};
        void get_xy(int &i, int &j){i=x; j=y;};
        friend coord operator--(coord &ob, int);
};

coord operator--(coord &ob, int){
    ob.x--;
    ob.y--;
}

int main(void){
    coord ob1(1,3);
    ob1--;
    int x,y;
    int i=10;
    i--;
    ob1.get_xy(x,y);
    cout << "(x,y)= " << "(" << x << "," << y << ")" << "\n";
    cout << i << endl;
    return 0;
}