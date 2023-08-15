/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover=0;
        //注意是<=cover
        //每次都取最大覆盖范围，每移动一个单位则更新最大覆盖范围
        //局部最优：每次取最大跳跃步数（即最大覆盖范围） 整体最优：得到整体最大覆盖范围
        for(int i=0; i<=cover; i++){
            cover=max(i+nums[i], cover);
            if(cover >= nums.size()-1){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

