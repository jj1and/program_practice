#include <iostream>
#include <cstdio>

using namespace std;

class date{
    private:
        int day, month, year;
    public:
        date(const char *str);
        date(int m, int d, int y){
            day = d;
            month = m;
            year = y;
        }
        void show(){
            cout << month << "/" << day << "/" << year << "\n";
        }
};

date::date(const char *str){
    sscanf(str, "%d%*c%d%*c%d", &month, &day ,&year);
}

int main(){
    date sdate("11/13/14");
    date idate(11,13,14);
    sdate.show();
    idate.show();
    return 0;
}