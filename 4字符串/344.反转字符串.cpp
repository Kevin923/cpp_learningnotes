/*
 * @lc app=leetcode.cn id=344 lang=cpp
 *
 * [344] 反转字符串
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution { //有库函数reverse
public:
    void swap(char &a, char &b){
        char tmp=a;
        a=b;
        b=tmp;
    }
    void reverseString(vector<char>& s) {
        int left=0;
        int right=s.size()-1;
        while(right>left){
            swap(s[left],s[right]);
            left++;
            right--;
        }
    }
};
// @lc code=end

