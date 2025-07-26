                            // BRUTE FORCE
// #include<iostream>
// #include<vector>
// using namespace std;
// int main(){
//     int arr[] = {5,1,3,0,4,9,6};
//     int n = sizeof(arr)/sizeof(arr[0]);
//     vector<int> v(arr,arr+n);
//     for(int i=0;i<n;i++){
//         cout<<v[i]<<" ";
//     }
//     cout<<endl;
//     int count = 0;
//     for(int i=0;i<n;i++){
//         for(int j= i+1;j<n;j++){
//             if(v[i]>v[j]) count++;
//         }
//     }
//     cout<<count;
// }
#include<iostream>
#include<vector>
using namespace std;
// int count = 0;
int inversion(vector<int>& a,vector<int>& b){
    int i=0, j=0;
    int count = 0;
    int m = a.size(), n = b.size();
    while(i<m && j<n){
        if(a[i]>b[j]) {
            count += m-i;
            j++;
        }
        else i++;
    }
    return count;
}
void merge(vector<int>& a,vector<int>& b,vector<int>& res){
    int m = a.size(), n = b.size();
    int i=0,j=0,k=0;
    while(i<m && j<n){
        if(a[i]<=b[j])    res[k++] = a[i++];
        else    res[k++] = b[j++];
    }
    if(i==m)    while(j<n) res[k++] = b[j++];
    if(j==n)    while(i<m) res[k++] = a[i++];
}
// void mergeSort(vector<int>& v){
int mergeSort(vector<int>& v){
    int count = 0;
    int n = v.size();
    if(n==1) return 0;
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
    count +=mergeSort(a);
    count +=mergeSort(b);
    //count inversions
    count += inversion(a,b);
    // merge
    merge(a,b,v);
    a.clear();
    b.clear();
    return count;
}
int main(){
    int arr[] = {5,1,3,0,4,2,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> v(arr,arr+n);
    int  o = v.size();
    for(int i=0;i<o;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<mergeSort(v);
}