#include <iostream>
#include <string>

using namespace std;

class Student{
protected:
  string name;
  int id_num;
  int math;
  int physics;
  int english;
public:
  Student(string name_init="", int math_init=0, int physics_init=0, int english_init=0 ){
    name = name_init;
    math = math_init;
    physics = physics_init;
    english = english_init;
  };
  void SetName(string set_name){
    name = set_name;
  };

};

int main(int argc, char const *argv[]) {
  /* code */
  return 0;
}
