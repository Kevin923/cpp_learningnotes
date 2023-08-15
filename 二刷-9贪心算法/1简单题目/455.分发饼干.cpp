/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int res = 0;
        int index = 0;
        for(int i = 0; i < g.size(); i++) {
            for(int j = index; j < s.size(); j++) {
                if(s[j] >= g[i]) {
                    res++;
                    index = j + 1;
                    break;
                }
            }
        }
        return res;

    }
};
// @lc code=end

