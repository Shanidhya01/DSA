#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.erase(2);
    int target = 40;
    // s.find() -> it searches in the set ans if 
    // if not found themn it return last element
    if(s.find(target)!=s.end()){  //  target exists
        cout<<"Exists"<<endl;
    }
    else cout<<"Not Exists"<<endl;
    cout<<s.size()<<endl;
    for(int elem : s){
        cout<<elem<<" ";
    }
    return 0;
}