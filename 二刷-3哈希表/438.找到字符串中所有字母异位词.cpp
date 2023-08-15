/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    //固定滑动窗口加哈希 
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if(p.size() > s.size()) return res;
        vector<int> vs(26, 0);
        vector<int> vp(26, 0);
        int l = 0, r = 0;
        //先固定滑动窗口长度大小为p得size
        for(int i = 0; i < p.size(); i++){
            vp[p[i] - 'a']++;
            vs[s[r] - 'a']++;
            r++;
        }
        if(vs == vp) res.push_back(l);
        while(r < s.size()){
            vs[s[r] - 'a']++;
            r++;
            vs[s[l] - 'a']--;
            l++;
            if(vp == vs){
                res.push_back(l);
            }
        }
        return res;
    }
};
// @lc code=end

