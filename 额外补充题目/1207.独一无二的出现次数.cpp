/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int hash[2001]={0}; //统计数字出现的频率
        


        for(int i = 0; i < arr.size(); i++){
            hash[arr[i] + 1000]++;
        }

        bool hash1[1001]={false}; //看相同频率是重复出现
        for(int i = 0; i <= 2000; i++){
            if(hash[i]){
                if(hash1[hash[i]] == false){
                    hash1[hash[i]] = true;
                }
                else return false;
            
            }
        }
        return true;
   
    }
};
// @lc code=end

