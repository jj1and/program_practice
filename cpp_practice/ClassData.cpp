#include "ClassData.hpp"

ClassData::ClassData(const char *file_name) : SchoolData(file_name){
}

void ClassData::DispClassData(void){
  std::printf("\n");
  std::printf("%-2s|%-6s|%-4s|%-4s|%-4s|\n","ID","お名前","数学","物理","英語");
  std::printf("----------------------------------\n");
  for(int i = 0; i < class_num; i++)
  {
    std::printf("%-2d|%-8s|%-4d|%-4d|%-4d|\n", stu[i].id_num, stu[i].name.c_str(), stu[i].math, stu[i].physics, stu[i].english);
  }
  std::printf("\n");
}

void ClassData::CalcClassProb(void){
  num_problems = class_num*1;
  std::cout << "クラス内の問題の数は" << num_problems << "です。" << std::endl;
}