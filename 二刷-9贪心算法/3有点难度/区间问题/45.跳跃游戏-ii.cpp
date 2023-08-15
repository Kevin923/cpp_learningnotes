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
        if(nums.size() == 1) return 0;
        int res = 0;
        int cur = 0; //当前覆盖
        int next = 0; //下一步覆盖        
        for(int i = 0; i < nums.size(); i++) {
            next = max(next, i + nums[i]);
            if(i == cur) {
                res++;
                cur = next;
                if(next >= nums.size() - 1){
                    break;
                } 
            }
        }
        return res;
    }
};
// @lc code=end

