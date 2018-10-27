#include <iostream>
using namespace std;

void set_hight_width(double& h, double& w){
    cout << "please input the figure's height and width" << endl;
    cout << "height= ";
    cin >> h;
    cout << "width= ";
    cin >> w;
};

class area_01 {
public:
    double height;
    double width;
};

class rectangle : public area_01{
    private:
        double rec_area;
    public:
        rectangle();
        void area();
};

class isoceles : public area_01{
    private:
        double iso_area;
    public:
        isoceles();
        void area();
};

rectangle :: rectangle(){
    double h, w;
    cout << "\nplease input the rectangle's height and width" << endl;
    cout << "height= ";
    cin >> h;
    cout << "width= ";
    cin >> w;
    this->height = h;
    this->width = w;
    cout << "height: " << this->height << ", width: " << this->width << endl;
};

void rectangle :: area(){
    this->rec_area = height*width;
    cout << "this rectangle's area is " << this->rec_area << endl;
};

isoceles :: isoceles(){
    double h, w;
    cout << "\nplease input the isoceles's height and width" << endl;
    cout << "height= ";
    cin >> h;
    cout << "width= ";
    cin >> w;
    this->height = h;
    this->width = w;
    cout << "height: " << this->height << ", width: " << this->width << endl;
};

void isoceles :: area(){
    this->iso_area = height*width/2.0;
    cout << "this isoceles's area is " << this->iso_area << endl;
};

int main(){
    rectangle rec;
    rec.area();
    
    isoceles iso;
    iso.area();
    return 0;
}