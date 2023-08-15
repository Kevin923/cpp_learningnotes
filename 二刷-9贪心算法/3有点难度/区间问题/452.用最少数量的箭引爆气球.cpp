/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        //从小到大
        return a[0] < b[0];
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        int res = 1;
        sort(points.begin(), points.end(), cmp);
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > points[i - 1][1]) {
                res++;
            }
            else{
                points[i][1] = min(points[i][1], points[i - 1][1]);
            }
        }
        return res;
    }
};
// @lc code=end

