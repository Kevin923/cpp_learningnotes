/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */
#include <string>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    //翻转整体字符串 左闭右闭
    void s_reverse(string &s,int start,int end){
        for(int i=start,j=end;i<j;i++,j--){
            swap(s[i],s[j]);
        }
    }

    //去除字符串中多余空格
    void del_space(string &s){
        int slow=0;
        for(int fast=0;fast<s.size();fast++){
            if(s[fast] != ' '){ //处理非空格字符 
                if(slow != 0){ //第一个单词前不用加空格，除第一个单词外，每读完一个单词都要加一个空格
                    s[slow]=' ';
                    slow++;
                }
                while(fast <s.size() && s[fast]!=' '){
                    s[slow++]=s[fast++];
                }
            }
        }
        s.resize(slow);
    }
    //将每个单词逐字母翻转
    string reverseWords(string s) { //"the sky is blue"  "blue is sky the"
        del_space(s);
        s_reverse(s,0,s.size()-1);
        int start=0;
        for(int i=0;i<=s.size();i++){
            if(i==s.size() || s[i]==' '){
                s_reverse(s,start,i-1);
                start=i+1;
            }
        }
        return s;
    }
};
// @lc code=end

