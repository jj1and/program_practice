#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>

class Student{
public:
  std::string name;
  int id_num;
  int math;
  int physics;
  int english;
  void SetStudent(int id_num_init, std::string name_init="", int math_init=0, int physics_init=0, int english_init=0 ){
    id_num = id_num_init;
    name = name_init;
    math = math_init;
    physics = physics_init;
    english = english_init;
  }

  void SetName(std::string set_name){ name = set_name; }
  void SetID(int set_id){ id_num = set_id; }
  void SetMathScore(int set_math){ math = set_math; }
  void SetPhysicsScore(int set_physics){ physics = set_physics; }
  void SetEnglishScore(int set_english){ english = set_english; }
};

#endif