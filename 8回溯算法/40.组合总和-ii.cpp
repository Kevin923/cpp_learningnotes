/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start

#include <vector>
#include <algorithm>
using namespace std;
// class Solution {
// private:
//     void backtracking(vector<int>& vec, int target, int sum, int index){
//         if(sum>target) return;
//         if(target == sum){
//             res.push_back(path);
//             return;
//         }  

//         for(int i=index; i<vec.size()&&sum+vec[i]<=target; i++){
//             //对同一树层使用过的元素跳过
//             if(i>index && vec[i]==vec[i-1]) continue;
//             path.push_back(vec[i]);
//             sum+=vec[i];
//             backtracking(vec, target, sum, i+1);
//             sum-=vec[i];
//             path.pop_back();
//         }
//         return;
//     }

// public:
//     vector<vector<int>> res;
//     vector<int> path;
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         res.clear();
//         path.clear();
//         sort(candidates.begin(), candidates.end());
//         backtracking(candidates, target, 0, 0);
//         return res;

//     }
// };

class Solution {
private:
    void backtracking(vector<int>& vec, int target, int sum, int index, vector<bool>& used){
        if(sum>target) return;
        if(target == sum){
            res.push_back(path);
            return;
        }  

        for(int i=index; i<vec.size()&&sum+vec[i]<=target; i++){
            //对同一树层使用过的元素跳过
            //used[i-1]=false 说明同一数层candidates[i-1]使用过
            //used[i-1]=true 说明同一树枝candidates[i-1]使用过

            if(i>0 && vec[i]==vec[i-1] && used[i-1]==false) continue;

            path.push_back(vec[i]);
            used[i]=true;
            sum+=vec[i];
            backtracking(vec, target, sum, i+1, used);
            sum-=vec[i];
            used[i]=false;
            path.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return res;

    }
};
// @lc code=end

