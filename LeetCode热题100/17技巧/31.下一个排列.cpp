/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
/*
12385764 -> 12386457
1.从后向前找 a[i + 1] > a[i] 的数 即5 7  12385764 此时7后面的数一定是降序
2.从后往前找 第一个比5大的数就是6 与5交换 12386754 (注意没有6的话  第一个比5大的数就是7)
3.升序754

如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 3 升序整个数组返回
12386457
*/
    void nextPermutation(vector<int>& nums) {
        int j = -1;
        for(int i = nums.size() - 1; i >= 1; i--) {
            if(nums[i] > nums[i - 1]) {
                j = i - 1;
                break;
            }
        }

        if(j != -1) {
            //注意是i > j
            for(int i = nums.size() - 1; i > j; i--) {
                if(nums[i] > nums[j]) {
                    swap(nums[i], nums[j]);
                    break;
                }
            }
        }

        reverse(nums.begin() + j + 1, nums.end());

    }
};
// @lc code=end

