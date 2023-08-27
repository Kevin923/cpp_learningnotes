/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
/*
遍历数组中每个元素num。逐一遍历每个元素会产生很多冗余工作，实际上我们
无需一次针对每个元素num去判断num+1，num+2，num+3...是否在数组中。
如果num-1已经在数组中的话，那么num-1肯定会进行相应的+1遍历，
然后遍历到num，而且从num-1开始的+1遍历必定比从num开始的+1遍历得到的序列长度更长。
因此，我们便可将在一个连续序列中的元素进行删减，让其只在最小的元素才开始+1遍历。
比如，现有元素[1,2,4,3,5]，当2,3,4,5发现均有比自己小1的元素存在，
那么它们就不会开始+1遍历，而1是连续序列中最小的元素，没有比自己小1的元素存在，
所以会开始+1遍历。
*/
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset(nums.begin(), nums.end());
        int res = 0;
        for(auto i = uset.begin(); i != uset.end(); i++) {
            int cur = *i;
            //只有当 i- 1不存在时，才往后遍历i + 1， i + 2， i + 3....
            if(uset.find(cur - 1) == uset.end()) {
                while(uset.find(cur + 1) != uset.end()) {
                    cur++;
                }
            }
            //[i, cur]是连续的，数字共有cur - (*i) + 1 个
            res = max(res, cur - (*i) + 1);
        }
        return res;
    }
};
// @lc code=end

