#include <iostream>  
#include <regex>  
#include <string>  
#include <vector>

using namespace std;
  
int main() {  
    std::string s = "Hello, world!";  
    std::regex e("\\w*");  // 匹配单词字符  
    std::smatch m;  
    if (std::regex_match(s, m, e)) {  
        std::cout << "Match found: " << m.str() << std::endl;  
    } else {  
        std::cout << "No match found." << std::endl;  
    }  
    return 0;  
}

// int main() {

//     string strs = "123 456 789";
 
//     std::istringstream iss(strs);
    
//     int a, b, c;  
//     iss >> a >> b >> c;
//     cout << a <<" "<< b <<" "<< c;

// }