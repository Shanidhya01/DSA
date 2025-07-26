#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v(5);
    int n = v.size();
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout<<v[i]<<"   ";
    }
}