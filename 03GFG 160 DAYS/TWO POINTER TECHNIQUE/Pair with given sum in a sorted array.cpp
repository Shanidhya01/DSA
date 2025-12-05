#include<bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int,int>m;
        int cnt = 0;
        for(int x : arr) m[x]++;
        for(int x : arr){
            int comp = target - x;
            if(m.find(comp) != m.end()){
                cnt += m[comp];
            }
            if(comp == x) cnt--;
        }
        return cnt/2;
    }
};