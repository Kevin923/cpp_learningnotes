/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    //直接只定义1个map 先遍历magazine 再遍历ransomNote
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.size() > magazine.size()) return false;
        int map1[26] = {0};
        int map2[26] = {0};
        for(int i = 0; i < ransomNote.size(); i++){
            map1[ransomNote[i] - 'a']++;
        }
        for(int j = 0; j < magazine.size(); j++){
            map2[magazine[j] - 'a']++;
        }
        for(int i = 0; i < 26 ; i++){
            if(map2[i] - map1[i] < 0){
                return false;
            }
        }
        return true;

    }
};
// @lc code=end

