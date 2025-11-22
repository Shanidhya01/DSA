// Vanya got n cubes. He decided to build a pyramid from them. Vanya wants to build the pyramid as follows: the top level of the pyramid must consist of 1 cube, the second level must consist of 1 + 2 = 3 cubes, the third level must have 1 + 2 + 3 = 6 cubes, and so on. Thus, the i-th level of the pyramid must have 1 + 2 + ... + (i - 1) + i cubes.

// Vanya wants to know what is the maximum height of the pyramid that he can make using the given cubes.

// Input
// The first line contains integer n (1 ≤ n ≤ 104) — the number of cubes given to Vanya.

// Output
// Print the maximum possible height of the pyramid in the single line.

// Examples
// Input
// 1
// Output
// 1
// Input
// 25
// Output
// 4


#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int height=0;
  for(int i=1;;i++){
      int cubesNeeded=i*(i+1)/2;
      if(n>=cubesNeeded){
          n-=cubesNeeded;
          height++;
      }
      else{
          break;
      }
  }
  cout<<height<<endl;
  return 0;
}