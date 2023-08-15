/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string str = to_string(n);
        int flag = str.size(); //防止1234这种没进入循环的被改变
        for(int i = str.size() - 1; i > 0; i--) {
            if(str[i-1] > str[i]) {
                str[i - 1]--;
                flag = i;
            }
        }

        //将flag到str.size()-1区间的每位数都变成9
        for(int i = flag; i < str.size(); i++) {
            str[i] = '9';
        }
        return stoi(str);
    }

};
// @lc code=end

