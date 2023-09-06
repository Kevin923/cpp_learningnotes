/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
//方法二： 类似环形链表二的思想
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        int pre1 = 0;
        int pre2 = slow;
        while(pre1 != pre2) {
            pre1 = nums[pre1];
            pre2 = nums[pre2];
        }
        return pre1;
    }
    
};
// @lc code=end

