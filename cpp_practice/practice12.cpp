#include<iostream>

using namespace std;

class strtyp{
    private:
        char *str;
        int len;
        int strlen(const char *s);
        void set_char(char *s);
        void set_char(const char *s);
        void free_mem(void);
    public:
        strtyp(void);
        strtyp(char *);
        strtyp(const char *);
        //strtyp(const strtyp &origin);
        strtyp operator+(strtyp s2);
        friend strtyp operator+(strtyp s, const char *string);
        friend strtyp operator+(const char *string, strtyp s);
        void print(void);
        //~strtyp(void);
};

strtyp::strtyp(void){
    const char *init = "init";
    this->set_char(init);
}

strtyp::strtyp(char *s){
    this->set_char(s);
}

strtyp::strtyp(const char *s){
    this->set_char(s);
}

/* strtyp::strtyp(const strtyp &origin){
    this->set_char(origin.str);
    cout << "copy constructor: " << this->len << endl;
} */

int strtyp::strlen(const char *s){
    int cnt = 0;
    for(int i=0; s[i]!='\0'; ++i){
        cnt++;
    }
    return cnt;
}

void strtyp::set_char(char *s){
    this->len = this->strlen(s);
    str = new char[this->len];
    for(int i=0;i<this->len;i++){
        str[i] = s[i];
    }
}

void strtyp::set_char(const char *s){
    this->len = this->strlen(s);
    str = new char[this->len];
    for(int i=0;i<this->len;i++){
        str[i] = s[i];
    }
}

void strtyp::free_mem(void){
    if(this->str != NULL){
        delete [] this->str;
      }
}

strtyp strtyp::operator+(strtyp s2){
    int comb_len;
    char *s;
    comb_len = this->len + s2.len;
    s = new char[comb_len];
    for(int i=0;i<comb_len;i++){
        if(i<(this->len)){
            s[i]=this->str[i];
        }
        else if((this->len)<=i){
            s[i]=s2.str[i-(this->len)];
        }
    }
    strtyp temp(s), result;
    if(s != NULL){
        delete [] s;
      }
    cout << "operator" << endl;
    result = temp;
    return result;
}

strtyp operator+(strtyp s1, const char *string){
    strtyp s2(string);
    int comb_len;
    char *s;
    comb_len = s1.len + s2.len;
    s = new char[comb_len];
    for(int i=0;i<comb_len;i++){
        if(i<s1.len){
            s[i]=s1.str[i];
        }
        else if(s1.len<=i){
            s[i]=s2.str[i-(s1.len)];
        }
    }
    strtyp temp(s);
    if(s != NULL){
        delete [] s;
      }
    return temp;
}

strtyp operator+(const char *string, strtyp s1){
    strtyp s2(string);
    int comb_len;
    char *s;
    comb_len = s1.len + s2.len;
    s = new char[comb_len];
    for(int i=0;i<comb_len;i++){
        if(i<s2.len){
            s[i]=s2.str[i];
        }
        else if(s2.len<=i){
            s[i]=s1.str[i-(s2.len)];
        }
    }
    strtyp temp(s);
    if(s != NULL){
        delete [] s;
      }
    return temp;
}

void strtyp::print(void){
    cout << this->str << endl;
    this->free_mem();
}

/* strtyp::~strtyp(void){
    if(this->str != NULL){
        delete [] this->str;
      }
      cout << "destructor:" << this->len << endl;
} */



int main(void){
    strtyp s1("hoge"), s2("piyopiyo"), s3;
    s3 = s1 + s2;
    s1.print();
    //s2.print();
    s3.print();
}