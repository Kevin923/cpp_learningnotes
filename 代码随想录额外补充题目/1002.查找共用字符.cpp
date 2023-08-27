/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int hash[26] = {0};
        for(int i = 0; i < words[0].size(); i++){
            hash[words[0][i] - 'a']++;
        }

        int hashtimes[26] = {0};
        for(int i = 1; i < words.size(); i++){
            memset(hashtimes, 0, 26*sizeof(int));
            for(int j = 0; j < words[i].size(); j++){
                hashtimes[words[i][j] - 'a']++;
            }

            for(int k = 0; k < 26; k++){
                hash[k] = min(hash[k], hashtimes[k]);
            }
        }

        for(int i = 0; i < 26; i++){
            while(hash[i] != 0){
                string s(1, 'a' + i);
                res.push_back(s);
                hash[i]--;
            }
        }

        return res;
     
    }
};
// @lc code=end

