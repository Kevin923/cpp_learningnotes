/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
//双指针
/*
在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 底边宽度 −1变短：

若向内 移动短板 ，水槽的短板 min(h[i],h[j])min(h[i], h[j])min(h[i],h[j]) 可能变大，
因此下个水槽的面积 可能增大 。
若向内 移动长板 ，水槽的短板 min(h[i],h[j])min(h[i], h[j])min(h[i],h[j])​ 不变或变小，
因此下个水槽的面积 一定变小 。
因此，初始化双指针分列水槽左右两端，循环每轮将短板向内移动一格，并更新面积最大值，直到两指针相遇时跳出；即可获得最大面积。

。
*/
    int maxArea(vector<int>& height) {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i < j) {
            if(height[i] < height[j]) {
                res = max(res, (j - i) * height[i]);
                i++;
            }
            else {
                res = max(res, (j - i) * height[j]);
                j--;
            }

        }
        return res;
    }
};
// @lc code=end

