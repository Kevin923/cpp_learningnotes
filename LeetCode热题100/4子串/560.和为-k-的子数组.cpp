/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
//本题不能使用双指针，因为包含负数，不能确定右指针往右移，和变大，
//左指针往右移，和变小 使用前缀和 + 哈希
/*
         1 2 3 4  6  8  9
前缀和   1 3 6 10 16 24 33
该题转化为 求 pre[i] - k 出现的次数
并且需要在哈希中先加入一个键值对 {0，1}表示pre[-1]= 0, 即和为0的次数已经出现了一次
*/
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, pre = 0;
        unordered_map<int, int> umap;
        umap[0] = 1;

        for(auto num: nums) {
            pre += num;
            if(umap.find(pre - k) != umap.end()) {
                res += umap[pre - k]; //注意不是res++
            }
            umap[pre]++;
        }
        return res;
    }
};
// @lc code=end

