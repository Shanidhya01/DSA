// three pointer
// leetcode 75
#include<iostream>
#include<vector>
using namespace std;
void sort01(vector<int>& v){
    int n = v.size();
    int low=0;
    int mid = 0;
    int high=n-1;
    while(mid<=high){
        if(v[mid]==2){
            int temp = v[mid];
            v[mid]= v[high];
            v[high] = temp;
            high--;
        }
        if(v[mid]==0){
                int tmp = v[mid];
                v[mid]= v[low];
                v[low] = tmp;
                mid++;
                low++;            
        }
        if(v[mid]==1){
                mid++;
        }
    }
}
int main(){
    vector<int>v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    // sort(v.begin(),v.end());
    sort01(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}