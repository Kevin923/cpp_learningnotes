/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int res=0;
        int nextdistance=0;
        int curdistance=0;
        for(int i=0; i<nums.size()-1; i++){
            nextdistance=max(i+nums[i], nextdistance);//下一步最大覆盖距离
            if(i == curdistance){ //当前移动下标等于当前最大覆盖距离
                curdistance=nextdistance;
                res++;
            }
        }
        return res;
    }       

};
// @lc code=end

