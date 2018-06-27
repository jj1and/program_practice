#include "SchoolData.hpp"

SchoolData::SchoolData(const char *file_name){
  std::ifstream ifs(file_name);
  int line_num=0;
  std::string line;
  if(!ifs){
    std::cout << "ファイルが開けません" << std::endl;
  }
  while(std::getline(ifs, line)){
    line_num++;
  }
  class_num = line_num;
  stu = new Student[class_num];
  ifs.clear();
  ifs.seekg(0);
  
  int id;
  std::string name;
  int math;
  int physics;
  int english;

  int i = 0;
  while(ifs >> id >> name >> math >> physics >> english){
    stu[i].SetStudent(id, name, math, physics, english);
    i++;
  }
}

void SchoolData::CalcMean(std::string subject){
  double sum = 0;
  if(subject=="math"){
    for(int i = 0; i < class_num; i++)
    {
      sum = sum + stu[i].math;
    }
    math_mean = sum/class_num;
    std::cout << "数学の平均点:" << math_mean << std::endl; 
  }

  else if(subject=="physics"){
    for(int i = 0; i < class_num; i++)
    {
      sum = sum + stu[i].physics;
    }
    physics_mean = sum/class_num;
    std::cout << "物理の平均点:" << physics_mean << std::endl; 
  }

  else if(subject=="english"){
    for(int i = 0; i < class_num; i++)
    {
      sum = sum + stu[i].english;
    }
    english_mean = sum/class_num;
    std::cout << "英語の平均点:" << english_mean << std::endl; 
  }
  else{
    std::cout << "一致する科目がありません" << std::endl;
  }
}

void SchoolData::CalcMax(std::string subject){
  int max=0;
  int max_id=class_num-1;
  if(subject=="math"){
    for(int i = 0; i < class_num; i++)
    {
      if(max<stu[i].math){
        max = stu[i].math;
        max_id = i;
      }
    }
    std::cout << "数学の最高点は" << stu[max_id].name << "さんで" << max << "点です。" <<std::endl;
  }

  if(subject=="physics"){
    for(int i = 0; i < class_num; i++)
    {
      if(max<stu[i].physics){
        max = stu[i].physics;
        max_id = i;
      }
    }
    std::cout << "物理の最高点は" << stu[max_id].name << "さんで" << max << "点です。" <<std::endl;
  }

  if(subject=="english"){
    for(int i = 0; i < class_num; i++)
    {
      if(max<stu[i].english){
        max = stu[i].english;
        max_id = i;
      }
    }
    std::cout << "英語の最高点は" << stu[max_id].name << "さんで" << max << "点です。" <<std::endl;
  }
}

void SchoolData::CalcPrivate(void){
  benefit = class_num*100;
  std::cout << "利益は" << benefit << "です。" << std::endl;
}

SchoolData::~SchoolData(){
      if(stu != NULL){
        delete [] stu;
      }
    }