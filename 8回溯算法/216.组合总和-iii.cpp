/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
using namespace std;

//剪枝
class Solution {
private:
    vector<vector<int>> res;
    vector<int> row;
    void backtracking(int k, int targetsum, int sum, int start){
        //剪枝
        if(sum > targetsum){
            return;
        }

        if(row.size()==k){
            if(sum ==  targetsum){
                res.push_back(row);
            }
            return;
        }

        for(int i=start; i<=9-(k-row.size())+1; i++)//剪枝
        {
            row.push_back(i);
            sum+=i;
            backtracking(k,targetsum,sum,i+1);
            sum-=i;
            row.pop_back();
        }

        return;
    }

public:
//找出所有相加之和为 n 的 k 个数的组合，只使用数字1-9，每个数字用一次
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        row.clear();
        backtracking(k, n, 0, 1);
        return res;
    }
};


class Solution {
private:
    vector<vector<int>> res;
    vector<int> row;
    void backtracking(int k, int n, int start){
        if(row.size()==k){
            int sum=0;
            for(int i=0; i<k; i++){
                sum+=row[i];
            }
            if(sum == n){
                res.push_back(row);
            }
            return;
        }

        for(int i=start; i<=9; i++){
            row.push_back(i);
            backtracking(k,n,i+1);
            row.pop_back();
        }

        return;
    }

public:
//找出所有相加之和为 n 的 k 个数的组合，只使用数字1-9，每个数字用一次
    vector<vector<int>> combinationSum3(int k, int n) {
        res.clear();
        row.clear();
        backtracking(k, n, 1);
        return res;
    }
};
// @lc code=end

