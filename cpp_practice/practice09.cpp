#include "ClassData.hpp"
#include "ClassData.cpp"

using namespace std;

int main(int argc, char const *argv[]) {
  const char *file_name="test.tsv";
  ClassData kadai_class(file_name);
  kadai_class.DispClassData();
  kadai_class.CalcMean("math");
  kadai_class.CalcMean("physics");
  kadai_class.CalcMean("english");
  
  kadai_class.CalcMax("math");
  kadai_class.CalcMax("physics");
  kadai_class.CalcMax("english");
  return 0;
}