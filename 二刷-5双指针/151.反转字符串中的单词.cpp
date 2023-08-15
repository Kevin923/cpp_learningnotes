/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    void reversestr(string &s, int i, int j){
        while(i < j){
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }

    void delspace(string& s){
        //移除空格和移除元素的思想一样
        int slow = 0;
        for(int fast = 0; fast < s.size(); fast++){
            if(s[fast] != ' '){
                //除了第一个单词前，其它每个单间都留有一个空格
                if(slow != 0){
                    s[slow] = ' ';
                    slow++;
                }

                while(fast < s.size() && s[fast] != ' '){
                    //和移除元素相同的操作
                    s[slow] = s[fast];
                    slow++;
                    fast++;
                }
             }
        }
        s.resize(slow);
    }
    //先删除空格
    //整体反转
    //逐个反转
    string reverseWords(string s){
        delspace(s);
        int l = 0;
        int r = s.size() - 1;
        reversestr(s, l, r);
        int start = 0;
        for(int i = 0; i <= s.size(); i++){
            
            if(s[i] == ' ' || i == s.size()){
                reversestr(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
    
};
// @lc code=end

