#include <iostream>

class MyClass {
public:
    static int staticVar;

    static void staticFunc() {
        staticVar--;
    }
};

int MyClass::staticVar = 100;

int main() {
    MyClass::staticFunc(); 
    std::cout << MyClass::staticVar << std::endl;//99
    MyClass obj;
    obj.staticVar--;
    std::cout << obj.staticVar << std::endl; //98
    obj.staticFunc();
    std::cout << obj.staticVar << std::endl; //97
    getchar();
    return 0;
}
