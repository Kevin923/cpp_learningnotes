/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <queue>
using namespace std;

// @lc code=start
class Solution {
public:
    //仿函数 函数对象 小顶堆
    class mycompare{
    public:
        bool operator()(const pair<int,int> &l,const pair<int,int> &r ){
            return l.second>r.second;  // 大于号是小顶堆 优先队列默认是大顶堆
        }
    };

    // priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
    //1.优先队列存储的类型  2.优先队列底层使用的存储结构 3.定义优先队列元素比较方式的类
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,mycompare> p_q;
        for(unordered_map<int,int>::iterator it=map.begin();it!=map.end();it++){
            p_q.push(*it);
            if(p_q.size()>k){
                p_q.pop();
            }
        }

        vector<int> res(k);
        for(int i=k-1;i>=0;i--){
            res[i]=(p_q.top().first);
            p_q.pop();
        }

        return res;
    }

};
// @lc code=end

