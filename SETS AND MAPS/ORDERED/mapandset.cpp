#include<iostream>
#include<set>
#include<map>
using namespace std;
int main(){
    // set<int> s;
    // s.insert(5);
    // s.insert(3);
    // s.insert(7);
    // for(auto ele : s){
    //     cout<<ele<<" ";
    // }
    map<string,int> m;
    m["Shanidhya"] = 23;
    m["Kumar"] = 15;
    m["Hello"] = 12;
    for(auto ele : m){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
}