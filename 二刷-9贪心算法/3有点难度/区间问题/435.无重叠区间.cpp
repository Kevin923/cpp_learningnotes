/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        //从小到大
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 0; //记录重叠区间个数
        int end = intervals[0][1]; //记录区间分割点
        for(int i = 1; i < intervals.size(); i++) {
            //无重叠
            if(intervals[i][0] >= end) {
                end = intervals[i][1];
            }
            //重叠
            else{
                count++;
                end = min(end, intervals[i][1]);
            }

        }
        return count;

    }
};
// @lc code=end

