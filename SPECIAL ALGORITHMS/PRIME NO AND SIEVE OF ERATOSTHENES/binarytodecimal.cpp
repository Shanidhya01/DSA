#include<iostream>
using namespace std;
int binary_to_decimal(string & binary){
    int n = binary.size();
    int result = 0;
    for(int i= n-1;i>=0;i--){
        int ch = binary[i];
        int num = ch -'0';
        result += num*(1 << (n-i-1));
    }
    return result;
}
string decimal_to_binary(int num){
    string result = "";
    while(num>0){
        if(num%2==0)    result+= "0";
        else result += "1";
        num /= 2;
    }
    return result;
}
int main(){
    string str = "001101";
    cout<<binary_to_decimal(str)<<endl;
    cout<<decimal_to_binary(13)<<endl;
    return 0;
}