/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    void reversestring(string &s, int a, int b){
        while(a < b){
            swap(s[a], s[b]);
            a++;
            b--;
        }
    }

    string reverseStr(string s, int k) {
        for(int i = 0; i < s.size(); i += (2 * k)){
            //翻转k个，注意坐标应该为{i, i + k -1} 如果是{i, i + k}则多了一个
            if(i + k - 1 < s.size()){
                reversestring(s, i, i + k - 1);
            }
            else{
                reversestring(s, i, s.size() - 1);
            }
        }
        return s;
    }
};
// @lc code=end

