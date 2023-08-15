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
        string str=to_string(n);
        int flag=str.size();
        for(int i=str.size()-1; i>=1; i--){
            if(str[i-1]>str[i]){
                str[i-1]--;
                flag=i;
            }
        }
        for(int i=flag; i<str.size(); i++){
            str[i]='9';
        }

        return stoi(str);
    }
};
// @lc code=end

