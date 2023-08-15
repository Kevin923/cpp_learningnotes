/*
 * @lc app=leetcode.cn id=452 lang=cpp
 *
 * [452] 用最少数量的箭引爆气球
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    //参数用引用，用形参会超时
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0){
            return 0;
        }
        sort(points.begin(), points.end(), cmp);
        int res=1;
        for(int i=1; i<points.size(); i++){
            //不重叠 箭+1
            if(points[i][0] > points[i-1][1]){
                res++;
            }
            //重叠 更新最小重叠右边界
            //如果气球重叠了，重叠气球中右边边界的最小值之前的区间一定需要一个弓箭。
            else{
                points[i][1]=min(points[i-1][1],points[i][1]);
            }
        }
        return res;
    }
};
// @lc code=end

