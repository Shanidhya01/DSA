#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void display(vector<int>& a){
    for(int i=0;i<a.size();i++){
    cout<<a[i]<<" ";
    }
    cout<<endl;
}
void reversepart(int i,int j,vector<int>& v){
    while(i<=j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++;
        j--;
    } 
}
int main(){
    vector<int>v;
    v.push_back(1);
    v.push_back(6);
    v.push_back(2);
    v.push_back(3);
    v.push_back(7);
    v.push_back(4);
    display(v);
    int k=9;
    int n = v.size();
    if(k>n)  k = k%n;
    // rotate
    reversepart(0,n-k-1,v);
    reversepart(n-k,n-1,v);
    reversepart(0,n-1,v);
    display(v);
}