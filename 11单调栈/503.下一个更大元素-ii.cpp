/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;

//直接合并两数组
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    
        stack<int> s;
        s.push(0);
        nums.insert(nums.end(), nums.begin(), nums.end());
        vector<int> res(nums.size(), -1);

        for(int i=1; i<nums.size(); i++){
            while(!s.empty() && nums[i]>nums[s.top()]){
                res[s.top()]=nums[i];
                s.pop();
            }  
            s.push(i);

        }
        res.resize(nums.size()/2);
        return res;

    }
};
// @lc code=end

