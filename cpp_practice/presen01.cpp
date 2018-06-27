#include <iostream>

using namespace std;

class watakushi
{
private:
    int age;
    double weight;
    double height;
public:
    watakushi(){
        age=22;
        weight=65.0;
        height=171.0;
        cout << "デフォルト設定を設定しました" << endl;
    }
    watakushi(int my_age, double my_weight, double my_height);
    friend void otomodachi(watakushi dareka);
    ~watakushi();
};

watakushi::watakushi(int my_age, double my_weight, double my_height){
    age = my_age;
    weight = my_weight;
    height = my_height;
    cout << "初期設定が完了しました" << endl;
}

watakushi::~watakushi()
{
    cout << "デストラクタが呼ばれました" << endl;
}

void otomodachi(watakushi dareka){
    cout << "この人の年齢は" << dareka.age << "歳です!!" << endl;
    cout << "それと体重は" << dareka.weight << "kgです!!" << endl;
    cout << "最後に身長は" << dareka.height << "cmです!!" << endl;
}

int main(int argc, char const *argv[])
{
    watakushi myself;
    otomodachi(myself);
    return 0;
}

