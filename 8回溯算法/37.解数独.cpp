/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
private:
    //二维回溯
    /*
        函数中不断地去调用if(backtracking(board))，从而来填充下一个位置上的数，如果最后一个数填充完毕后，return true,代表找到了
        一组解，逐层返回true，返回到第一层直接返回true。
        如果某一层返回了false; 则代表次层的上一层应该进行回溯了，这个位置已经填好的数应该重新填
    */
    bool backtracking(vector<vector<char>>& board){
        for(int row=0; row<board.size(); row++){
            for(int col=0; col<board[0].size(); col++){
                if(board[row][col]=='.'){
                    for(char k='1'; k<='9'; k++){
                        if(isvalid(row, col, k, board)){
                            board[row][col]=k;
                            //如果找到合适的一组，立刻返回
                            if(backtracking(board)) return true;
                            board[row][col]='.';
                        }
                    }

                    return false;
                }
            }
        }
        return true; //遍历完没有返回false；说明找到了合适棋盘位置了
    }

    bool isvalid(int row, int col, char k,vector<vector<char>>& board){
        //数字 1-9 在每一行只能出现一次。
        //注意：是i<9,不是i<col
        for(int i=0; i<9; i++){
            if(board[row][i] == k){
                return false;
            }
        }
        //数字1-9 在每一列只能出现一次
        for(int i=0; i<9; i++){
            if(board[i][col] == k){
                return false;
            }
        }
        //数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
        int startrow=(row/3)*3;
        int startcol=(col/3)*3;

        //9*9的区域 将整个区域划分成九个3*3区域，startrow,startcol为其中某个区域的开始位置
        for(int i=startrow; i<startrow+3; i++) {
            for(int j=startcol; j<startcol+3; j++){
                if(board[i][j]==k){
                    return false;
                }
            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

