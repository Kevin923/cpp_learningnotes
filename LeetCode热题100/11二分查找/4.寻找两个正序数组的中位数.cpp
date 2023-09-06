/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
using namespace std;

//二分查找 有点难
class Solution {
public:
    /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
        * 这里的 "/" 表示整除
        * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
        * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
        * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
        * 这样 pivot 本身最大也只能是第 k-1 小的元素
        * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
        * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
        * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
    */
   /*
   1 3 6 9
   2 5 8     返回5   len = 4 + 3 = 7   (7 / 2) + 1 = 4 

   */

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int len = m + n;
        int left = -1, right = -1;
        int astart = 0, bstart = 0;
        for(int i = 0; i <= len / 2; i++) {
            left = right;
            if(astart < m && nums1[astart] < nums2[bstart] && bstart < n) {
                right = nums1[astart++];
            }
            else if(bstart < n && nums1[astart] >= nums2[bstart] && astart < m) {
                right = nums2[bstart++];
            }
            else if(astart >= m) {
                right = nums2[bstart++];
            }
            else {
                right = nums1[astart++];
            }
        }
        if(len % 2 == 1) {
            return right;
        }
        else {
            return (left + right) / 2.0;
        }



    }
};
// @lc code=end

