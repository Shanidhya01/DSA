#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    // insertimg / input do not use []
    v.push_back(6);
    cout<<v.capacity()<<endl;
    v.push_back(1);
    cout<<v.capacity()<<endl;
    v.push_back(9);
    cout<<v.capacity()<<endl;
    v.push_back(0);
    cout<<v.capacity()<<endl;
    // if you want to update or access use []
    // v[0]=67;
    // cout<<v[0]<<" ";
    // cout<<v[1]<<" ";
    // cout<<v[2]<<" ";
    // cout<<v[3]<<" ";
    return 0;
}
