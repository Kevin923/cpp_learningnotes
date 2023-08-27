/*
 * @lc app=leetcode.cn id=941 lang=cpp
 *
 * [941] 有效的山脉数组
 */

// @lc code=start
#include <vector>
using namespace std;


// class Solution {
// public:
//     bool validMountainArray(vector<int>& arr) {
//         int len = arr.size();
//         if(len < 3) return false;
//         int index=0;
//         //1.从小到大 2.小到大到小
//         for(int i = 1; i < arr.size(); i++){
//             if(arr[i] > arr[i-1]){
//                 continue;
//             }
//             else if(arr[i] == arr[i-1]){
//                 return false;
//             }
//             else{
//                 if(i == 1) return false;
//                 else{
//                     index=i;
//                     break;
//                 }

//             }
//         }
//         for(int i = index + 1; i < arr.size(); i++){
//             if(arr[i] < arr[i-1]){
//                 continue;
//             }
//             else{
//                 return false;
//             }
//         }
//         return true;
//     }
// };


//双指针
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int len = arr.size();
        if(len < 3) return false;
        int left = 0;
        int right = len - 1;

        while(left < len - 1 && arr[left] < arr[left + 1]){
            left++;
        }
        while(right > 0 && arr[right] < arr[right - 1]){
            right--;
        }
        if(left == right && left != 0 && right != len-1) return true;
        return false;
    }
};


// @lc code=end

