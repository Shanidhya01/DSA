#include<iostream>
#include<vector>
using namespace std;
void permutations(vector<string>& v,string ans , string original){
    if(original==""){
        v.push_back(ans);
        return ;
    }
    int m =original.length();
    for(int i=0;i<m;i++){
        char ch = original[i];
        string left = original.substr(0,i);
        string right = original.substr(i+1);
        permutations(v,ans+ch,left+right);
    }
}
int main(){
    string str = "123";
    vector<string> v;
    permutations(v,"",str);
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<endl;
    }
    // cout<<str.substr(1,2);
}