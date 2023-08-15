/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

//双指针
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int slow = 0;
        for(int fast = 0; fast < nums.size(); fast++){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        //删除数组中值为val的元素 并返回新数组的长度
        return slow;
    }
};
// @lc code=end

