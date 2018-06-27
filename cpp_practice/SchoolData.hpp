#ifndef SCHOOLDATA
#define SCHOOLDATA
#include "Student.hpp"
#include <iostream>
#include <fstream>

class SchoolData{
    private:
        int benefit;
    protected:
        int class_num;
        double math_mean;
        double physics_mean;
        double english_mean;
        Student *stu;
    public:
        SchoolData(const char *file_name);
        void CalcMean(std::string subject);
        void CalcMax(std::string subject);
        virtual void CalcPrivate(void);
        ~SchoolData();

};

#endif