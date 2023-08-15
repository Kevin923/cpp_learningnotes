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
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return 0;
        sort(intervals.begin(), intervals.end(), cmp);
        int res=0;
        //只判断重叠情况即可
        for(int i=1; i<intervals.size(); i++){
            //重叠情况
            if(intervals[i][0] < intervals[i-1][1]){
                intervals[i][1]=min(intervals[i][1],intervals[i-1][1]);
                res++;
            }
        }
        return res;
    }
};
// @lc code=end

