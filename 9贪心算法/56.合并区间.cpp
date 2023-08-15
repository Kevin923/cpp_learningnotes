/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), cmp);

        res.push_back(intervals[0]);
        for(int i=1; i<intervals.size(); i++){
            //有重叠
            if(res.back()[1]>=intervals[i][0]){
                res.back()[1]=max(res.back()[1],intervals[i][1]);
            }
            else{
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

