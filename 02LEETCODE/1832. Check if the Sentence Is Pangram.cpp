#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size() < 26)     return false;
        
        unordered_map<char, int> mp;

        for(int i=0; i<sentence.size(); i++){
            mp[sentence[i]]++;
        }
        if(mp.size() == 26) return 1;
        return 0;
    }
};