#include<iostream>
#include<vector>
using namespace std;
int main(){
    // if size is given then do like this
    // vector<int> v(5);
    // for(int i=0;i<5;i++){
    //     cin>>v[i];
    // }
    // if size not given 
    vector<int> v;
    for(int i=0;i<5;i++){
       int x;
       cin>>x;
       v.push_back(x);
    }    
    for(int i=0;i<5;i++){
        cout<<v[i]<<" ";
    }      
}