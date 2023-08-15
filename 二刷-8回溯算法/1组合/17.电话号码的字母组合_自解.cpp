/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<char, string> umap;
    vector<string> res;
    string path;
    void back(string str, int k, int index){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = index; i < str.size(); i++){
            for(int j = 0; j < umap[str[i]].size(); j++){
                path += umap[str[i]][j];
                back(str, k, i + 1);
                path.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        umap.insert(pair<char, string>('2', "abc"));
        umap.insert(pair<char, string>('3', "def"));
        umap.insert(pair<char, string>('4', "ghi"));
        umap.insert(pair<char, string>('5', "jkl"));
        umap.insert(pair<char, string>('6', "mno"));
        umap.insert(pair<char, string>('7', "pqrs"));
        umap.insert(pair<char, string>('8', "tuv"));
        umap.insert(pair<char, string>('9', "wxyz"));
        res.clear();
        path.clear();
        if(digits.size() == 0) return res;
        int k = digits.size();
        back(digits, k, 0);
        return res;
    }
};
// @lc code=end

