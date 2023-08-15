/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<string>> res;
    void backtracking(vector<string>& chess, int n, int row){
        //终止条件
        if(row == n){
            res.push_back(chess);
            return;
        }

        //单层搜索逻辑
        for(int col=0; col<n; col++){
            if(isvalid(row, col, chess, n)){
                chess[row][col]='Q';
                backtracking(chess, n, row+1);
                chess[row][col]='.';//回溯撤销
            }
        }
        return;
    }

    bool isvalid(int row, int col, vector<string> chess, int n){
        //检查列
        for(int i=0; i<row; i++){
            if(chess[i][col]=='Q'){
                return false;
            }
        }
        //检查45度 左侧斜上
        for(int i=row-1,j=col-1; i>=0 && j>=0; i--,j--){
            if(chess[i][j] == 'Q'){
                return false;
            }
        }
        //检查135度 右侧斜上
        for(int i=row-1,j=col+1; i>=0 && j<n; i--,j++){
            if(chess[i][j] == 'Q'){
                return false;
            }
        }
       return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        vector<string> chess(n,string(n,'.'));
        backtracking(chess, n, 0);
        return res;
    }
};
// @lc code=end

