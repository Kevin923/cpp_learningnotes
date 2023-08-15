/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // //1.哈希表
        // if(s.size()!=t.size())
        //     return false;
        // unordered_map<char,int> map;
        // for(int i=0;i<s.size();i++){
        //     map[s[i]]++;
        //     map[t[i]]--;
        // }
        // for(unordered_map<char,int>::iterator it=map.begin();it!=map.end();it++){
        //     if(it->second!=0){
        //         return false;
        //     }
        // }
        // return true;
        
        //2.辅助数组
        int arr[26]={0};
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
            arr[t[i]-'a']--;       
        }
        for(int i=0;i<26;i++){
            if(arr[i]!=0) return false;
        }
        return true;

    }
};
// @lc code=end

