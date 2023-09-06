/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
private:
    int size;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int,int>>::iterator> umap;
public:

    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) return -1;
        auto keyvalue = *umap[key]; //解引用类型为pair<int,int>
        //将其移到链表头，先后面删除
        cache.erase(umap[key]);//erase参数是迭代器指针
        cache.push_front(keyvalue);//添加到首部
        umap[key] = cache.begin(); //更新映射关系， 即新的迭代器位置
        return keyvalue.second;
    }
    
    void put(int key, int value) {
        //不存在
        if(umap.find(key) == umap.end()) {
            if(cache.size() == size) {
                //删除映射对
                umap.erase(cache.back().first);
                cache.pop_back();//尾部删除
            }
        }
        else {
            cache.erase(umap[key]);
        }
        /*
        cache.push_back({key, value});
        umap[key] = cache.back();//将报错
        std::list 容器在进行插入操作后，其迭代器可能会失效。这是因为插入操作可能会导致容器重新分配内存，从而导致之前的迭代器变得无效。

        具体说，在你的情况中，cache.push_back({key, value}) 可能会使得之前的迭代器 cache.back() 失效，
        这意味着将失效的迭代器赋值给 umap[key] 可能会导致错误。
        为了避免这种情况，应该在使用迭代器前确保它们仍然有效。
        */


        cache.push_front({key, value});
        umap[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

