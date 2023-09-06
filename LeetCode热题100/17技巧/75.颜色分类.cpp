/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
using namespace std;
//荷兰国旗问题
class Solution {
public:
//双指针 p0 p1 从头往后遍历 遇见0 交换 两个指针同时 后移， 遇见1 交换
//p1后移 
    // void sortColors(vector<int>& nums) {
    //     int p0 = 0;
    //     int p1 = 0;
    //     for(int i = 0; i < nums.size(); i++) {
    //         if(nums[i] == 1) {
    //             swap(nums[i], nums[p1]);
    //             p1++;
    //         }
    //         else if(nums[i] == 0) {
    //             swap(nums[i], nums[p0]);
    //             if(p0 < p1) {
    //                 swap(nums[i], nums[p1]);
    //             }
    //             p0++;
    //             p1++;
    //         }
    //     }
    // }

    //刷油漆法
    /*
    我来解释一下。首先，所有数都≤2，那么索性把所有数组置为2，然后遇到所有≤1的，就再全部置为1，
    覆盖了错误的2，这时候所有2的位置已经正确，最后所有≤0的全部置为0，也就覆盖了一些错误的1，这时候，0和1的位置都正确。
    最重要的就是需要两个指针指向下一个1或0的位置
    */
    void sortColors(vector<int>& nums) {
        int n0 = 0;
        int n1 = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            nums[i] = 2;
            if(num < 2) {
                nums[n1++] = 1;
            }
            if(num < 1) {
                nums[n0++] = 0;
            }
        }

    }

};
// @lc code=end

