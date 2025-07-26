#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> v;
    // insertimg / input do not use []
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);
    v.push_back(0);
    v.push_back(9);
    v.push_back(40);
    v.push_back(1);
    v.push_back(9);
    v.push_back(10);
    v.push_back(9);
    v.push_back(10);
    v.push_back(6);
    v.push_back(1);
    v.push_back(9);
    v.push_back(0);
    v.push_back(9);
    v.push_back(40);
    v.push_back(1);
    v.push_back(9);
    v.push_back(10);
    v.push_back(9);
    v.push_back(10);
    cout<<"size is : "<<v.size()<<endl;
    cout<<"capacity is : "<<v.capacity()<<endl;
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout<<"size is : "<<v.size()<<endl;
    cout<<"capacity is : "<<v.capacity()<<endl;
   
}