/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
#include <algorithm>
using namespace std;
/*
移除多余空格
将整个字符串反转
将每个单词反转
举个例子，源字符串为："the sky is blue "

移除多余空格 : "the sky is blue"
字符串反转："eulb si yks eht"
单词反转："blue is sky the"
*/
class Solution {
public:
    //移除多余空格 移除元素的思想 双指针
    void delspace(string& s){
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++){
            if(s[fast] != ' '){
                if(slow != 0)//刨去第一个位置不能为空格，每个单词之间添加空格
                {
                    s[slow] = ' ';
                    slow++;
                }
                while(fast < s.size() && s[fast] != ' '){
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
            }
        }
        //重置size
        s.resize(slow);
    }

    //反转字符串 左闭右闭
    void reversestr(string& s, int start, int end){
        while(start < end){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }

    string reverseWords(string s) {
        delspace(s);
        //剔除多余空格后反转整个字符串
        reversestr(s, 0, s.size() - 1);

        //逐个反转  i <=  s.size() 因为最后一个字符串的关系
        int start = 0;
        for(int i = 0; i <= s.size(); i++){
            if(i == s.size() || s[i] == ' '){
                reversestr(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};
// @lc code=end

