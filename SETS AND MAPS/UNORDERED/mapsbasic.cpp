#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<string,int> m;
    pair<string,int> p1;
    p1.first = "Shanidhya";
    p1.second = 7;
    m.insert(p1);

    m["Kumar"] = 15;
    m["Hello"] = 12;

    for(auto elem : m){
        cout<<elem.first<<" "<<elem.second<<endl;
    }
    m.erase("Kumar");
    for(auto elem : m){
        cout<<elem.first<<" "<<elem.second<<endl;
    }
}