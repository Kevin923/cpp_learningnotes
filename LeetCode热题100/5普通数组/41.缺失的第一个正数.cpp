/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
#include <vector>
using namespace std;
//官方题解哈希 或者 置换两种方法
//置换的方法和剑指offer中的 数组中重复的数字 比较像
class Solution {
public:
/*
index   0 1  2  3  n = 4 res = 2
        3 4 -1  1
        
        -1 4 3  1
        -1 1 3  4
        1 -1 3  4
        实际上，对于一个长度为 N的数组，其中没有出现的最小正整数只能在 [1,N+1]中。这是因为如果 [1,N] 都出现了，
        那么答案是 N+1，否则答案是 [1,N]中没有出现的最小正整数。

*/  

    //原地置换法
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            //nums[nums[i] - 1] != nums[i]避免陷入死循环 两个数相等一直交换
            while(nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
    
};
// @lc code=end

