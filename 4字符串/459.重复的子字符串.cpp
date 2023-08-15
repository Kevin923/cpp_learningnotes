/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    void getNext(int *next,string &s) {
        int j=0;
        next[0]=0;
        for(int i=1;i<s.size();i++){
            while(j>0 && s[i] != s[j]){
                j=next[j-1];
            }
            if(s[i]==s[j]){
                j++;
            }
            next[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        //移动匹配算法
        // string t=s+s;
        // // t.erase(t.begin());
        // // t.erase(t.end()-1);
        // t=t.substr(1,t.size()-2);
        // //static const size_type npos = -1;
        // // if(t.find(s) != std::string::npos){ 
        // //     return true;
        // // }
        // if(t.find(s)==-1) return false;
        // return true;

        //KMP算法
        if(s.size()==0)
            return false;
        int next[s.size()];
        getNext(next,s);
        int len=s.size();
        if(next[len-1]!=0 && len%(len-(next[len-1]))==0){
            return true;
        }
        return false;

    }
};
// @lc code=end

