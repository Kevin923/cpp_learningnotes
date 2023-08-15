/*
 * @lc app=leetcode.cn id=674 lang=cpp
 *
 * [674] 最长连续递增序列
 */

// @lc code=start
#include <vector>
using namespace std;


//暴力
// class Solution {
// public:
//     //[1,3,5,4,7] 输出：3 即[1,3,5]
//     int findLengthOfLCIS(vector<int>& nums) {
//         if(nums.size()==1) return 1;
//         int res=1;
//         vector<int> vc;
//         for(int i=0; i<nums.size()-1; i++){
//             if(nums[i+1]>nums[i]){
//                 res++;
//                 if(i+1 == nums.size()-1){
//                     vc.push_back(res);
//                 }
//             }
//             else{
//                 vc.push_back(res);
//                 res=1;
//             }
//         }
//         int maxvalue=0;
//         for(auto i: vc){
//             if(i>maxvalue){
//                 maxvalue=i;
//             }
//         }
//         return maxvalue;
//     }
// };

//dp
class Solution {
public:
    //[1,3,5,4,7] 输出：3 即[1,3,5]
    int findLengthOfLCIS(vector<int>& nums) {
        int len=nums.size();
        if(len <= 1) return len;

        vector<int> dp(nums.size(),1);
        for(int i=1; i<nums.size(); i++){
            for(int j=i-1; j<i; j++){
                if(nums[i]>nums[j]){
                    dp[i]=dp[j]+1;
                }
                //直接去掉else也可
                // else{
                //     dp[i]=1;
                // }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
// @lc code=end

