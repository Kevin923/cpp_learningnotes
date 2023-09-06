/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;
/*
[0,1,2,4,5,6,7] 在下标 3 处经旋转后可能变为 [4,5,6,7,0,1,2] 。

给你 旋转后 的数组 nums 和一个整数 target ，如果 nums 中
存在这个目标值 target ，则返回它的下标，否则返回 -1 。
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        4567 012
        456 7012
        15670 12
        将数组一分为二，其中一定有一个是有序的，另一个可能是有序，
        也能是部分有序。
        此时有序部分用二分法查找。无序部分再一分为二，其中一个
        一定有序，另一个可能有序，可能无序。就这样循环. 
        */
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) {
            return nums[0] == target ? 0 : -1;
        }

        int right = nums.size() - 1;
        int left = 0;

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            }

            //左半边是有序的 
            if(nums[0] <= nums[mid]) {
                //左半边是有序的 并且target在左边
                if(nums[0] <= target && target < nums[mid]) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
            //右半边有序
            else {
                if(nums[mid] < target && target <= nums[n - 1]) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }

            }

        }
        return -1;
    }
};
// @lc code=end

