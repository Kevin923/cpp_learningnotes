#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void bubble (vector<int>& nums) {

    int n = nums.size();
    //外循环
    for(int i = n - 1; i > 0; i--) {
        bool flag = false;
        for(int j = 0; j < i; j++) {
            if(nums[j] > nums[j + 1]) {
                flag = true;
                swap(nums[j], nums[j + 1]);
            }
        }
        if(flag == false){
            break;
        }
    }
}

void select(vector<int>& nums) {
    int n = nums.size();
    //外循环 
    for(int i = 0; i < n - 1; i++) {
        int k = i;
        for(int j = i + 1; j < n; j++) {
            if(nums[j] < nums[k]) {
                k = j;
            }
        }
        swap(nums[i], nums[k]);
    }
}  

void insert(vector<int>& nums) {
    int n = nums.size();
    for(int i = 1; i < n; i++) {
        if(nums[i] < nums[i - 1]) {
            int base = nums[i];
            int j = i - 1;
            while (j >= 0 && base < nums[j]) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = base;
        }
    }
}

void quicksort(vector<int>& nums, int left, int right) {
    if(left >= right) return;

    int i = left;
    int j = right;
    while(i < j) {
        while(i < j && nums[j] >= nums[left]) j--;
        while(i < j && nums[i] <= nums[left]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);

    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);

}

//快排基准数优化
void quicksort1(vector<int>& nums, int left, int right) {
    if(left >= right) return;

    int i = left;
    int j = right;
    int index = rand() % (right - left + 1) + left;
    int target = nums[index];
    //以nums[left] 作为基准数
    swap(nums[index], nums[left]);

    while(i < j) {
        while(i < j && nums[j] >= nums[left]) j--;
        while(i < j && nums[i] <= nums[left]) i++;
        swap(nums[i], nums[j]);
    }
    swap(nums[left], nums[i]);

    quicksort(nums, left, i - 1);
    quicksort(nums, i + 1, right);

}

void merge(vector<int>& nums, vector<int>& help, int low, int high) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    int start1 = low, end1 = mid;
    int start2 = mid + 1, end2 = high;

    //递归划分
    merge(nums, help, start1, end1);
    merge(nums, help, start2, end2);

    //合并
    int index = low;
    while(start1 <= end1 && start2 <= end2) {
        help[index++] = nums[start1] < nums[start2] ? nums[start1++] : nums[start2++];
    }

    while(start1 <= end1) {
        help[index++] = nums[start1++];
    }

    while(start2 <= end2) {
        help[index++] = nums[start2++];
    }

    for(index = low; index <= high; index++) {
        nums[index] = help[index];
    }
} 

void siftdown(vector<int>& nums, int start, int end) {
    int cur = start;
    int left = 2 * cur + 1;
    int tmp = nums[cur];
    while(left <= end) {
        if(left < end && nums[left] < nums[left + 1]) {
            left++;
        }
        if(tmp >= nums[left]) break;
        
        else{
            swap(nums[left], nums[cur]);
        }

        cur = left;
        left = 2 * left + 1;
    }
}

void maxheap(vector<int>& nums) {
    //将数组建堆 （最大堆）
    int n = nums.size();
    for(int i = n / 2 - 1; i >= 0; i-- ) {
        siftdown(nums, i, n - 1);
    }

    //循环取出堆顶元素 再调整堆
    for(int i = n - 1; i > 0; i--) {
        swap(nums[i], nums[0]);
        siftdown(nums, 0, i - 1);
    }
}

//计数排序
void countsort(vector<int>& nums) {
    int n = nums.size();
    int MAX = INT_MIN;
    for(auto num: nums) {
        MAX = max(MAX, num);
    }
    vector<int> counter(MAX + 1, 0);
    for(int i = 0; i < nums.size(); i++) {
        counter[nums[i]]++;
    }

    //求counter前缀和数组
    for(int i = 0; i < MAX; i++) {
        counter[i + 1] += counter[i];
    }   
    vector<int> res(n, 0);
    //对nums数组从后向前遍历 counter[num] - 1,代表num在结果数组中最后出现位置的索引
    for(int i = n - 1; i >= 0; i--) {
        int num = nums[i];
        res[counter[num] - 1] = num;
        counter[num]--;
    }
    nums = res;
}

int main() {

    vector<int> vc{2,3,3,1,1,0,0,4};
    vector<int> help(vc.size());
    //bubble(vc);
    select(vc);
    //insert(vc);
    //quicksort1(vc, 0, vc.size() - 1);

    //merge(vc, help, 0, vc.size() - 1);
    maxheap(vc);

    //countsort(vc); //计数排序
    
    for(auto num: vc){
        cout << num << " ";
    }
    cout << endl;
    getchar();
    return 0;
}