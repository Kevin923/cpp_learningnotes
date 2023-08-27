/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int i: nums){
            sum += i;
        }
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 0; i < nums.size(); i++){
            leftsum += nums[i];
            rightsum = sum - leftsum + nums[i];
            if(leftsum == rightsum) return i;
        }
        return -1;
    }
};
// @lc code=end

