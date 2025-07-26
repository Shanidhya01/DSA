#include <iostream>
using namespace std;
int main()
{   int n;
 cout<<"ENTER NUMBER :";
 cin>>n;

   int a=1;
   char c='A';
    for(int i=n-1;i>=1;i--)
    {  c='A';
        for(int j=1;j<=i;j++)
    {
        cout<<" ";
    }
    for(int k=1;k<=a;k++)
    {
       cout<<c++;

    }
    a=a+2;
    cout<<endl;
    }
    
    for(int i=1;i<=n;i++)
    {  c='A';
        for(int j=1;j<i;j++)
        {
            cout<<" ";
        }
        for(int k=1;k<=a;k++)
        {
            cout<<c++;
            
        }
        a=a-2;
        cout<<endl;
    }
}