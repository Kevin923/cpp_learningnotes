/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> maxheap;
    priority_queue<int, vector<int>, less<int>> minheap;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(maxheap.size() == minheap.size()) {
            minheap.push(num);
            int tmp = minheap.top();
            minheap.pop();
            maxheap.push(tmp);
        }
        else {
            maxheap.push(num);
            int tmp = maxheap.top();
            maxheap.pop();
            minheap.push(tmp);
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()) {
            return (maxheap.top() + minheap.top()) / 2.0;
        }
        else{
            return maxheap.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

