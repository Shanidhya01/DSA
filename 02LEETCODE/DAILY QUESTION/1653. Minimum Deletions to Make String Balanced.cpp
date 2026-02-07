#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int count_a = 0,count_b = 0,min_deletion = n;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') count_a++;
        }
        for(int i=0;i<n;i++){
            if(s[i] == 'a') count_a--;
            min_deletion = min(min_deletion,count_a+count_b);
            if(s[i] == 'b') count_b++;
        }
        return min_deletion;
    }
};