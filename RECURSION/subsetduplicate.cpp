#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void storeSubset(string ans, string original, vector<string>& v,bool flag){
    if(original ==""){
        v.push_back(ans);
        return;
    }
    char ch = original[0];
    if(original.length()==1){
        if(flag==true)   storeSubset(ans+ch,original.substr(1),v,true);
        storeSubset(ans,original.substr(1),v,true);  
        return;
    }
    char dh = original[1];
    if(ch==dh){
        if(flag==true)   storeSubset(ans+ch,original.substr(1),v,true);
        storeSubset(ans,original.substr(1),v,false);  
    }
    else{
        if(flag==true)   storeSubset(ans+ch,original.substr(1),v,true);
        storeSubset(ans,original.substr(1),v,true); 
    }
}
int main(){
    string str = "0";
    vector<string> v;
    storeSubset("",str,v,true);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}