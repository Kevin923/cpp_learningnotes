#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


//多重背包和0-1背包问题很像，把多重背包数量展开，就是0-1背包问题
void test_multibag(){
    vector<int> weight{1,3,4};
    vector<int> value{15,20,30};
    vector<int> nums{2,3,2};
    int bagweight=10;

    for(int i=0; i<nums.size(); i++){
        while(nums[i]>1){
            weight.push_back(weight[i]);
            value.push_back(value[i]);
            nums[i]--;
        }
    }

    vector<int> dp(bagweight+1,0);

    for(int i=0; i<weight.size(); i++){
        for(int j=bagweight; j>=weight[i]; j--){
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
        for(int i=0; i<=bagweight; i++){
            cout<<dp[i]<<" ";
        }
        cout<<endl;
    }



    cout<<dp[bagweight]<<endl;

}

int main(){
    test_multibag();
    getchar();
    return 0;
}