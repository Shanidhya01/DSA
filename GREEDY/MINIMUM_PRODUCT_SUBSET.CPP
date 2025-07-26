// minimum product subset
#include <bits/stdc++.h>
using namespace std;
int minProduct(vector<int> &nums){
    int countnegative = 0;
    int countzero = 0;
    int countpositive = 0;
    int productpositive = 1;
    int productnegative = 1;
    int largestnegative = INT_MIN;
    for(int i=0;i<int(nums.size());i++){
        if(nums[i]==0) countzero++;
        else if(nums[i]<0){
            countnegative++;
            productnegative *= nums[i];
            largestnegative = max(largestnegative,nums[i]);
        }
        else{
            countpositive++;
            productpositive *= nums[i];
        }
    }
    if(countnegative  == 0){
        if(countzero > 0) return 0;
        else{
            auto minele = min_element(nums.begin(),nums.end());
            return *minele;
        }
    }
    else{
        if(countnegative%2==0){
            return (productnegative/largestnegative)*productpositive;
        }
        else{
            return productnegative*productpositive;
        }
    }
}
int main(){
    vector<int> nums{0,1,2,3,4};
    cout<<minProduct(nums)<<"\n";
    return 0;
}