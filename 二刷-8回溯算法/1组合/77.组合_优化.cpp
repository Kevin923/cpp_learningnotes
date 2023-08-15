/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
/*
剪枝操作：
已经选择的元素个数：path.size();
所需需要的元素个数为: k - path.size(); 
列表中剩余元素（n-i） >= 所需需要的元素个数（k - path.size()）
在集合n中至多要从该起始位置 : i <= n - (k - path.size()) + 1，开始遍历
为什么有个+1呢，因为包括起始位置，我们要是一个左闭的集合。
举个例子，n = 4，k = 3， 目前已经选取的元素为0（path.size为0），
n - (k - 0) + 1 即 4 - ( 3 - 0) + 1 = 2。
从2开始搜索都是合理的，可以是组合[2, 3, 4]。
*/
    vector<vector<int>> res;
    vector<int> path;
    void back(int n, int k, int index){
        if(k == path.size()){
            res.push_back(path);
            return;
        }

        for(int i = index; i <= n - (k - path.size()) + 1; i++){
            path.push_back(i);
            back(n, k, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        back(n, k, 1);
        return res;
    }
};
// @lc code=end

