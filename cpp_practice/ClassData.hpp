#ifndef CLASSDATA_HPP
#define CLASSDATA_HPP
#include "Student.hpp"
#include <iostream>
#include <fstream>


class ClassData{
  private:
    double math_mean;
    double physics_mean;
    double english_mean;
    int class_num;
    Student *stu;
  public:
    ClassData(const char *file_name);
    void CalcMean(std::string subject);
    void CalcMax(std::string subject);
    void DispClassData();
    ~ClassData();

};

#endif