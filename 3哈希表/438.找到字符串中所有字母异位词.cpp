/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution { //难  看答案做的滑动窗口
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
            return {};
        int l=0;
        int r=0;
        vector<int> s1(26,0);
        vector<int> p1(26,0);
        vector<int> res;
        for(int i=0;i<p.size();i++){
            p1[p[i]-'a']++;
            s1[s[r]-'a']++;
            r++;
        }
        if(s1==p1) res.push_back(l);
        //固定滑动窗口的大小为字符串p的长度
        while(r < s.size()){
            s1[s[r]-'a']++;
            r++;
            s1[s[l++]-'a']--;
            if(s1==p1){
                res.push_back(l);
            }
        }

        return res;
    }



};
// @lc code=end

