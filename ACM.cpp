#include <bits/stdc++.h> //万能引用
#include <string>
#include <iostream>
using namespace std;

// 输入一行字符串，包括空格
// int main() {
    
//     string s;
//     //如果输入的字符串 是 abcd这种 中间没有空格，则可以直接
//     //cin >> s;

//     // 这里一定要getline, 否则遇到空格会断掉读取
//     getline(cin, s); 
//     //cout << s.size() << endl; //包含空格
//     for(int i = 0; i < s.size(); i++) {
//         cout << s[i];
//     }
    
//     /*
//     //就可以按如下方式写题 其中solve是我们的解题函数
//     while(getline(cin, s)) {
//         string ans = solve(s);
//         cout << ans << endl;
//     }
//     */
// }

// int main() {
//     int n;
//     while(cin >> n) {
//         //解决过程


//         //输出答案
//         cout << n << endl;
//     }
//     return 0;
// }

//在终端的一行中输入固定数目的整型数字，并存到数组中，中间以空格分隔。
/*
3
1 2 3 
*/
// int main() {
//     int n;
//     cin >> n;
//     vector<int> nums(n);
//     for(int i = 0; i < n; i++) {
//         cin >> nums[i];
//     }
// }

//在终端的一行中输入非固定数目的整型数字，并存到数组中，中间以空格（或者其他单字符,./）分隔。
// 1 2 3
// int main() {
//     vector<int> nums;
//     int num;
//     while(cin >> num) {
//         nums.push_back(num);
//         if(cin.get() == '\n') break;
//     }
//     for(auto i: nums) {
//         cout << i << " ";
//     }
// }

//3、在终端的一行中输入固定数目的整型数字，并存到数组中，中间以（其他单字符,./）分隔。
//1,2,3

// int main() {
//     int m;
//     cin >>  m;
//     char sep;
//     vector<int> nums(m);
    
//     for (int i = 0; i < m - 1; ++i){
//         cin >> nums[i] >> sep;
//     }
//     cin >> nums[m - 1];

//     for(auto i: nums) {
//         cout << i << " ";
//     }
// }

//给定一行字符串，每个字符串用空格间隔，一个样例为一行 输出 1 2 3 输出 6
// int main() {
// 	string input;
// 	while (getline(cin, input)) {  //读取一行
// 		stringstream data(input);  //使用字符串流
// 		int num = 0, sum = 0;
// 		while (data >> num) {
// 			sum += num;
// 		}
// 		cout << sum << endl;
// 	}
// 	return 0;
// }

/*
给定一行字符串，每个字符串用逗号间隔，一个样例为一行

方法：使用getline 读取一整行字符串到字符串input中，
然后使用字符串流stringstream，读取单个数字或者字符。每个字符中间用','间隔

输入：1,2,3
输出：1 2 3
*/
// int main() {
// 	string input;
// 	while (getline(cin, input)) {  //读取一行
//         vector<string> strs;
//         string str;
//         stringstream ss(input);
//         while(getline(ss, str,',')){
//             strs.push_back(str);
//         }
//         sort(strs.begin(), strs.end());
		
//         for (auto& str : strs) {
// 			cout << str << " ";
// 		}
// 		cout << endl;
//     }
// 	return 0;

/*
给定一行字符串，每个字符串用空格间隔，一个样例为一行
示例： daa ma yello
*/
int main() {
	string str;
	vector<string> strs;
	while (cin >> str) {
		strs.push_back(str);
		if (getchar() == '\n') {  //控制测试样例           
			for (auto& str : strs) {
				cout << "current:"<< str << " ";
			}
			cout << endl;
			strs.clear();
		}
	}
	return 0;
}


