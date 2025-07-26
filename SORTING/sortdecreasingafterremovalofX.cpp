#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){ 
    string s = "AZYZXBDJKX";
    string str="";
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]>='X'){
            str.push_back(s[i]);
        }
    }
    // sort(str.begin(),str.end());
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] < str[j + 1]) {
                swap(str[j], str[j + 1]);
            }
        }
    }
    reverse(str.begin(),str.end());
    cout<<s;
    cout<<endl;
    cout<<str;
}