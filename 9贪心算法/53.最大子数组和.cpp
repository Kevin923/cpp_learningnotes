/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res=INT32_MIN; //返回最大和
        if(nums.size() == 1){
            return nums[0];
        }
        int count=0;
        for(int i=0; i<nums.size(); i++){
            count+=nums[i];
            //res=res<count?count:res;
            if(res < count){
                res=count;
            }
            if(count <= 0){
                count=0;
            }
        }

        return res;
    }
};
// @lc code=end

