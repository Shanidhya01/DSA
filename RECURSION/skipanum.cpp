#include<iostream>
#include<vector>
using namespace std;
void removeNum(vector<int>& a,int arr[],int idx,int size){
    if (idx == size) {
        for (int num : a) {
            cout << num << " ";
        }
        return;
    }
    int c = arr[idx];
    if(c==1) removeNum(a,arr,idx+1,size);
    else{
        a.push_back(c);
        removeNum(a,arr,idx+1,size);
    } 
}
int main(){
    int arr[8] = {1,2,3,1,1,4,1,7};
    vector<int> a;
    removeNum(a,arr,0,8);
}