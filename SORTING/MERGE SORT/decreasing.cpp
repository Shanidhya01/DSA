#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& a,vector<int>& b,vector<int>& res){
    int m = a.size();
    int n = b.size();
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(a[i]>=b[j])    res[k++] = a[i++];
        else    res[k++] = b[j++];
    }
    if(i==m){
        while(j<n) res[k++] = b[j++];
    }
    if(j==n){
        while(i<m) res[k++] = a[i++];
    }
}
void mergeSort(vector<int>& v){
    int n = v.size();
    if(n==1) return ;
    int n1 = n/2;
    int n2 = n- n/2;
    vector<int> a(n1) , b(n2);
    for(int i=0;i<n1;i++){
        a[i] = v[i];
    }
    for(int i=0;i<n2;i++){
        b[i] = v[i+n1];                        
    }
    // recursion
    mergeSort(a);
    mergeSort(b);
    // merge
    merge(a,b,v);
    a.clear();
    b.clear();
}
int main(){
    int arr[] = {5,1,3,0,4,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
    int  o = v.size();
    for(int i=0;i<o;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    mergeSort(v);
    for(int i=0;i<o;i++){
        cout<<v[i]<<" ";
    }
}