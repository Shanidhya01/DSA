#include<iostream>
#include<climits>
using namespace std;
    void three_largest(int arr[],int arr_size)
    {
        int i,first,second,third;
        if(arr_size <3)
        {
            cout<<"INVALID INPUT ";
        }
        third=first=second=INT_MIN;
          for (i = 0; i < arr_size; i ++) 
    {
        if (arr[i] > first) 
        {
            third = second; 
            second = first; 
            first = arr[i]; 
        }
        else if (arr[i] > second) 
        {
            third = second; 
            second = arr[i]; 
        }
        else if (arr[i] > third) 
            third = arr[i]; 
        }
        if(second == INT_MIN)
        {
            cout<<"2nd and 3rd not present";
        }
        else{
            cout<<"\nFIRST : " << first<<endl;
            cout<<"SECOND  : " << second<<endl;
            cout<<"THIRD   : " << third<<endl;
        }
    }
int main()
{
    int nums[] = {7}; 
    int n = sizeof(nums)/sizeof(nums[0]); 
    cout << "Original array: "; 
    for (int i=0; i < n; i++) 
        cout << nums[i] <<" "; 
    three_largest(nums, n); 
    return 0; 
}