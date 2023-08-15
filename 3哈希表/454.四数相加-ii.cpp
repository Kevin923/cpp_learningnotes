/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution { //经典 <int,int> <a+b的值,出现的次数> 
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> umap;  //  <a+b的值,出现的次数>
        for(int A:nums1){
            for(int B: nums2){
                umap[A+B]++;
            }
        }
        int count=0;   //记录a+b+c+d=0 出现的次数
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++){
                if(umap.find(0-(nums3[i]+nums4[j])) != umap.end())
                {
                    count+=umap[0-(nums3[i]+nums4[j])];
                }
            }
        }
        return count;

    }
};
// @lc code=end

