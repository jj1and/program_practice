#ifndef CLASSDATA_HPP
#define CLASSDATA_HPP
#include "SchoolData.hpp"


class ClassData : public SchoolData {
  private:
    int num_problems;
  public:
    ClassData(const char *file_name);
    void CalcClassProb(void);
    void DispClassData(void);

};

#endif