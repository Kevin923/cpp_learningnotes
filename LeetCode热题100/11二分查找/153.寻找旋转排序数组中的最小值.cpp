/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
using namespace std;

/*
我们考虑数组中的最后一个元素 x：在最小值右侧的元素
（不包括最后一个元素本身），它们的值一定都严格小于 x；
而在最小值左侧的元素，它们的值一定都严格大于 x。因此，
我们可以根据这一条性质，通过二分查找的方法找出最小值。


就是边界值小于中间值的时候中间值肯定不是最小值所以 low = mid + 1 边界值大于
中间值的时候 中间值可能会是最小值所以 high = mid 保留mid避免错过
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nums[0];
        int left = 0;
        int right = n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            //mid在最小值 右侧 则可以忽略二分查找的右半部分
            if(nums[mid] < nums[right]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return nums[left];
   
    }
};
// @lc code=end

