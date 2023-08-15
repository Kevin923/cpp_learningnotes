#include <iostream>
using namespace std;

/*
 *单例模式
 *构造、析构、拷贝构造、赋值 私有化
*/
class Singleton {
public:
    static Singleton& getInstance();

private:
    Singleton() {
        cout << "gouzao" << endl;
    }

    ~Singleton() {
        cout << "xigou" << endl;
    }

    Singleton(const Singleton& s);

    const Singleton& operator=(const Singleton& s);

};


Singleton& Singleton::getInstance() {
    static Singleton instance; // 内部静态变量初始化是线程安全的
    return instance;
}

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    if (&s1 == &s2) {
        std::cout << "s1 and s2 refer to the same instance." << std::endl;
    }
    getchar();
    return 0;
}
