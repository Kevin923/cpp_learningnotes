/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    //正常基于快排超时
    int quicksort(vector<int>& nums, int k, int left, int right) {

        int index = rand() % (right - left + 1) + left; // 生成一个 l - r的随机数 再加上l
        //随机获取一个值作为目标值

        //保存目标值
        int target=nums[index];
        //在进行第一次交换时，会丢失nums[left],因此需要保存
        nums[index]=nums[left];
        int i=left,j=right;
        while(i<j){
            while(i<j&&nums[j]<=target) j--;
            nums[i]=nums[j];
            while(i<j&&nums[i]>=target) i++;
            nums[j]=nums[i];
        }
        nums[i]=target;
        //经过交换后，i左部均大于nums[i],右部均小于nums[i]
        if(i==k-1) return nums[i];
        //说明在左部分
        else if(i>k-1) return quicksort(nums,k,left,i-1);
        else return quicksort(nums,k,i+1,right);
     
    }

    int findKthLargest(vector<int>& nums, int k) {
        return quicksort(nums, k, 0, nums.size() - 1);
    }
};
// @lc code=end

