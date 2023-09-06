#include <iostream>
using namespace std;

int main() {
    //指针常量 int* const p(const位于指针的右侧，即*的右侧, 底层const) 表示该常量是一个指针类型的常量
    //指针自身的值是一个常量不可以改变，始终指向一个地址，但指针地址中存的内容可以改变
    int a = 10;
    int b = 20;
    int* const p = &a;
    *p = 20;
    //p = 100; //报错 不能改变p的地址值
    cout << *p << endl; //20

    //常量指针 顶层const
    /*
    常量指针，本质上是一个指针，常量表示指针所指向的内容，不可以改变，指针的地址可以改变
    int const *p;顶层const
    const int *p
    */
   const int c = 30;
   int d = 40;
   const int* p1 = &c;
   //*p1 = 100; //报错 

   p1 = &d;
   cout << *p1 << endl; //40
 
    
}

