#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxlen = 0 , start = 0;
        unordered_map<int,int> m ;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            while(m.size() > 2){
                m[fruits[start]]--;
                if(m[fruits[start]] == 0){
                    m.erase(fruits[start]);
                }
                start++;  
            }
            maxlen = max(maxlen,i -start +1);
        }
        return maxlen;
    }
};