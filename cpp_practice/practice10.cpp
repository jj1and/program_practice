#include<iostream>
#include<math.h>

using namespace std;

void ordering(double *points, int len){
    double tmp_x, tmp_y;
    for(int i=0;i<len-2;i=i+2){
        for(int j=i+2; j<len-2; j=j+2){
            if(points[i]>points[j]){
                tmp_x = points[i];
                tmp_y = points[i+1];
                points[i] = points[j];
                points[i+1] = points[j+1];
                points[j] = tmp_x;
                points[j+1] = tmp_y;
            }
        }
    }
}

void inverse_xy(double *points, int len){
    double tmp_x,tmp_y;
    for(int i=0;i<len-2;i=i+2){
         tmp_x = points[i];
         tmp_y = points[i+1];
         points[i] = tmp_y;
         points[i+1] = tmp_x;
    }
}

class triangle{
    private:
        double x[3];
        double y[3];
    public:
        void set_points(double *points);
        double calc_area(void);
        double area;
};

void triangle::set_points(double *set_points){
    for(int i=0; i < 6; i=i+2){
        x[i/2]=set_points[i];
        y[i/2]=set_points[i+1];
    }
}

double triangle::calc_area(void){
    double l[3];
    double cos_t12;
    for(int i=0; i<3; i++){
        l[i] = sqrt((x[i+1]-x[i])*(x[i+1]-x[i])+(y[i+1]-y[i])*(y[i+1]-y[i]));
        if(i==2){
            l[i] = sqrt((x[i]-x[i-2])*(x[i]-x[i-2])+(y[i]-y[i-2])*(y[i]-y[i-2]));
        }
    }
    if(l[0]*l[1]*l[2]!=0){
        cos_t12 = (l[2]*l[2]-l[1]*l[1]-l[0]*l[0])/(2*l[0]*l[1]);
        area = l[0]*sqrt(1-cos_t12*cos_t12)*l[1]/2.0;
    }
    else{
        area = 0.0;
    }
    return area;
}

class squre{
    private:
        double points_1[6], points_2[6];
        double points[8];
        double area;
        triangle tri1, tri2;
        void set_points(double *points);
        void calc_area(void);
    public:
        squre(void);
        squre(double set_area);
        squre(double *set_points);
        void print_area(void);
        void get_area(double &a){a = this->area;}
        squre operator+(squre s2);

};

squre::squre(void){
    for(int i=0; i<8; i++){
            this->points[i]=0;
        }
    this->set_points(this->points);
    this->calc_area();
}

squre::squre(double set_area){
    if(set_area<=0){
        if(set_area<0){
            cout << "set positive number!!" <<"\n";
        }
        for(int i=0; i<8; i++){
            this->points[i]=0;
        }
    }
    else if(set_area>0){
        double init[8]={0,0,0,1,1,0,1,1};
        for(int i=0; i<8; i++){
            this->points[i]=init[i]*sqrt(set_area);
        }
    }
    this->set_points(this->points);
    this->calc_area();
}

squre::squre(double *set_points){
    this->set_points(set_points);
    this->calc_area();
}

void squre::set_points(double *set_points){
    double y_ordered[6];
    ordering(set_points, 8);
    for(int i = 0;i<6;i=i+2){
        this->points_1[i]=set_points[i];
        this->points_1[i+1]=set_points[i+1];
        y_ordered[i]=set_points[i];
        y_ordered[i+1]=set_points[i+1];
    }
    inverse_xy(y_ordered, 6);
    ordering(y_ordered, 6);
    inverse_xy(y_ordered, 6);
    if(y_ordered[5]<set_points[7]){
        this->points_2[0] = y_ordered[2];
        this->points_2[1] = y_ordered[3];
        this->points_2[2] = y_ordered[4];
        this->points_2[3] = y_ordered[5];
        this->points_2[4] = set_points[6];
        this->points_2[5] = set_points[7];
        
    }
    else{
        this->points_2[0] = y_ordered[0];
        this->points_2[1] = y_ordered[1];
        this->points_2[2] = y_ordered[4];
        this->points_2[3] = y_ordered[5];
        this->points_2[4] = set_points[6];
        this->points_2[5] = set_points[7];
    }

    
}

void squre::calc_area(void){
    double tr1_area, tri2_area;
    this->tri1.set_points(this->points_1);
    this->tri2.set_points(this->points_2);
    this->area = this->tri1.calc_area()+this->tri2.calc_area();
}

void squre::print_area(void){
    this->calc_area();
    cout << this->area << "\n";
}

squre squre::operator+(squre s2){
    double temp_area;
    temp_area = this->area + s2.area;
    squre temp(temp_area);
    return temp;
}

int main(void){
    double test1[8]={1,0,0,2,2,3,3,1};
    double test2[8]={1,0,0,1,1,1,0,0};
    squre s1(test1), s2(test2), s3;
    s3 = s1 + s2;
    s3.print_area();
    return 0;
}