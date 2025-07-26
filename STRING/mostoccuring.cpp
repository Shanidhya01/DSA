// leetcode 242
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    // string s;
    // cin>>s;
    // int n = s.length();
    // int max = 0;
    // for(int i=0;i<n;i++){
    //     char ch = s[i];
    //     int count = 1;
    //     for(int j=i+1;j<n;j++){
    //         if(s[j] == s[i]) count ++;
    //     }
    //     if(max<count) max = count;
    // }
    // for(int i=0;i<n;i++){
    //     char ch = s[i];
    //     int count = 1;
    //     for(int j=i+1;j<n;j++){
    //         if(s[j] == s[i]) count ++;
    //     }
    //     if(max==count){
    //         cout<<ch<<" "<<max<<endl;
    //     }
    // }
    string s = "leetcode";
    int n = s.length();
    vector<int> arr(26,0);
    for(int i=0;i<n;i++){
        char ch =s[i];
        int ascii = (int)ch;
        arr[ascii-97]++;
    }
    int mx =0;
    for(int i=0;i<26;i++){
        if(arr[i]>mx) mx = arr[i];
    }

    for(int i=0;i<26;i++){
        if(arr[i] == mx){
            int ascii = i+97;
            char ch = (char)ascii;
            cout<<ch<<" "<<mx<<endl;
        }
    }
}