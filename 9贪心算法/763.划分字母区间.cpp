/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27]={0};
        //记录每个英文字母最后出现的位置
        for(int i=0; i<s.size(); i++){
            hash[s[i]-'a']=i;
        }
        vector<int> res;
        int right=0;
        int left=0;
        for(int i=0; i<s.size(); i++){
            right=max(right,hash[s[i]-'a']); //找到字符出现的最远边界
            if(i==right){
                res.push_back(right-left+1);
                left=i+1;
            }
        }
        return res;
    }
};
// @lc code=end

