/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    class mycompare{
    public:
        bool operator()(const pair<int, int>& l, const pair<int, int>& r){
            return l.second > r.second; //小顶堆自定义
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> umap; //统计每个数出现的频率
        for(int i = 0; i < nums.size(); i++){
            umap[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int, int>>, mycompare> pq;
        for(auto i : umap){
            pq.push(i);
            //始终维护k个大小的小顶堆，超过k时每次弹出堆顶元素，即最小值，最后则剩下k个最大的值
            //即出现频率最多的元素
            if(pq.size() > k){
                pq.pop();
            }
        }
        //如果要使用res[i]这么直接赋值，应该定义res的时候写好res的大小
        vector<int> res(k, 0);
        //倒叙输出 因为弹出的先是最小值
        for(int i = k - 1; i >= 0; i--){
            res[i] = pq.top().first;
            pq.pop();
        }
        return res;
    }
};
// @lc code=end

