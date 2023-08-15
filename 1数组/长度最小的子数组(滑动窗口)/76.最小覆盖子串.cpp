/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> hs; 
        unordered_map<char,int> ht;
        for(int i=0;i<t.size();i++){ //创建hash表 统计t中字符出现的次数
            ht[t[i]]++;
        }
        string res;
        int ans=0;  //有效添加的字符数
        //i滑动窗口有边界   j左边界
        for(int i=0,j=0;i<s.size();i++){
            hs[s[i]]++; 
            //如果当前字符是字符串t中的字符，出现次数不超过在
            //t中的出现次数，则添加到窗口中记作一次有效添加
            if(hs[s[i]]<=ht[s[i]]){ 
                ans++;
            }

            //移动左边界，缩小窗口
            while(j<i && hs[s[j]]>ht[s[j]]) //窗口中字符出现的次数超过在t中出现的次数
            {
                hs[s[j]]--;
                j++;
            }
            //当窗口中的字符已经包含了字符串中的所有字符
            if(ans==t.size())
            {
                //更新最小覆盖字串
                if(res.empty() || res.size()>i-j+1)
                    res=s.substr(j,i-j+1);
            }
        }
        return res;
    }
};
// @lc code=end

