#include <iostream>
#include <cstring>
using namespace std;

//重写String

class String{
public:
    //默认构造
    String(const char* str = nullptr);
    //拷贝
    String(const String& str);
    //赋值
    String& operator=(const String& str);
    //析构
    ~String();

    char* c_str(){
        return m_data;
    }
    int Size() {
        return size;
    }

private:
    char* m_data;
    int size;
};

String::String(const char* str) {
    //判断是否为空
    if(str == nullptr) {
        m_data = new char[1];
        m_data[0] = '\0';
        size = 0;
    }
    else {
        size = strlen(str);
        m_data = new char[size + 1];
        strcpy(m_data, str);
    }
}

String::~String(){
    delete[] m_data;
    m_data = nullptr;
}

String::String(const String& str){
    //size = strlen(str.m_data);
    size = str.size;
    m_data = new char[size + 1];
    strcpy(m_data, str.m_data);
}

String& String::operator=(const String& str){
    if(&str == this) {
        return *this;
    }
    size = strlen(str.m_data);
    delete[] m_data;
    m_data = new char[size + 1];
    strcpy(m_data, str.m_data);
    return *this;
}

int main() {
    String str1 = "";
    String str2("2333");
    cout << str1.c_str() << endl;
    cout << str2.c_str() << endl;

    String str3(str1);
    cout << str3.c_str() << endl;
    cout << str1.Size() << endl;

    getchar();
    return 0;
}
