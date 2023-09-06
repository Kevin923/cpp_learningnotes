/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
//二分版本O(logmn) 
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0, high = n * m - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            int row = mid / n; //注意 是 mid / n  不是m
            int col = mid % n;
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

