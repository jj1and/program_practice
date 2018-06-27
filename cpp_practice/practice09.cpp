#include "SchoolData.hpp"
#include "SchoolData.cpp"
#include "ClassData.hpp"
#include "ClassData.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
  const char *file_name="test.tsv";

  SchoolData kadai_school(file_name);
  kadai_school.CalcPrivate();
  kadai_school.CalcMean("math");

  ClassData kadai_class(file_name);
  kadai_class.DispClassData();
  kadai_class.CalcMean("math");
  kadai_class.CalcMean("physics");
  kadai_class.CalcMean("english");
  
  kadai_class.CalcMax("math");
  kadai_class.CalcMax("physics");
  kadai_class.CalcMax("english");
  kadai_class.CalcPrivate();
  return 0;
}