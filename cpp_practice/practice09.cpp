#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Student{
public:
  string name;
  int id_num;
  int math;
  int physics;
  int english;
  void SetStudent(int id_num_init, string name_init="", int math_init=0, int physics_init=0, int english_init=0 ){
    id_num = id_num_init;
    name = name_init;
    math = math_init;
    physics = physics_init;
    english = english_init;
  }

  void SetName(string set_name){ name = set_name; }
  void SetID(int set_id){ id_num = set_id; }
  void SetMathScore(int set_math){ math = set_math; }
  void SetPhysicsScore(int set_physics){ physics = set_physics; }
  void SetEnglishScore(int set_english){ english = set_english; }
};

class ClassData{
  private:
    double math_mean;
    double physics_mean;
    double english_mean;
    int class_num;
    Student *stu;
  public:
    ClassData(const char *file_name);
    void CalcMean(string subject);
    void CalcMax(string subject);
    ~ClassData();

};

ClassData::ClassData(const char *file_name){
  ifstream ifs(file_name);
  int line_num=0;
  string line;
  if(!ifs){
    cout << "ファイルが開けません" << endl;
  }
  while(getline(ifs, line)){
    line_num++;
  }
  class_num = line_num;
  stu = new Student[class_num];
  ifs.clear();
  ifs.seekg(0);
  
  int id;
  string name;
  int math;
  int physics;
  int english;

  int i = 0;
  while(ifs >> id >> name >> math >> physics >> english){
    stu[i].SetStudent(id, name, math, physics, english);
    i++;
  }
}

void ClassData::CalcMean(string subject){
  double sum = 0;
  if(subject=="math"){
    for(int i = 0; i < class_num; i++)
    {
      sum = sum + stu[i].math;
    }
    math_mean = sum/class_num;
    cout << "数学の平均点:" << math_mean << endl; 
  }

  else if(subject=="physics"){
    for(int i = 0; i < class_num; i++)
    {
      sum = sum + stu[i].physics;
    }
    physics_mean = sum/class_num;
    cout << "物理の平均点:" << physics_mean << endl; 
  }

  else if(subject=="english"){
    for(int i = 0; i < class_num; i++)
    {
      sum = sum + stu[i].english;
    }
    english_mean = sum/class_num;
    cout << "英語の平均点:" << english_mean << endl; 
  }
  else{
    cout << "一致する科目がありません" << endl;
  }
}

void ClassData::CalcMax(string subject){
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
    cout << "数学の最高点は" << stu[max_id].name << "さんで" << max << "点です。" <<endl;
  }

  if(subject=="physics"){
    for(int i = 0; i < class_num; i++)
    {
      if(max<stu[i].physics){
        max = stu[i].physics;
        max_id = i;
      }
    }
    cout << "物理の最高点は" << stu[max_id].name << "さんで" << max << "点です。" <<endl;
  }

  if(subject=="english"){
    for(int i = 0; i < class_num; i++)
    {
      if(max<stu[i].english){
        max = stu[i].english;
        max_id = i;
      }
    }
    cout << "英語の最高点は" << stu[max_id].name << "さんで" << max << "点です。" <<endl;
  }
}

ClassData::~ClassData(){
      if(stu != NULL){
        delete [] stu;
      }
    }


int main(int argc, char const *argv[]) {
  const char *file_name="test.tsv";
  ClassData kadai_class(file_name);
  kadai_class.CalcMean("math");
  kadai_class.CalcMax("math");
  return 0;
}