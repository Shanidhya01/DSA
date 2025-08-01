// Asen and Boyan are playing the following game. They choose two different positive integers K and L, and start the game with a tower of N coins. Asen always plays first, Boyan – second, after that – Asen again, then Boyan, and so on. The boy in turn can take 1, K or L coins from the tower. The winner is the boy, who takes the last coin (or coins). After a long, long playing, Asen realizes that there are cases in which he could win, no matter how Boyan plays. And in all other cases Boyan being careful can win, no matter how Asen plays.
// So, before the start of the game Asen is eager to know what game case they have. Write a program coins which help Asen to predict the game result for given K, L and N.
// INPUT
// The input describes m games.
// The first line of the standard input contains the integers K, L and m, 1 < K < L < 10, 3 < m < 50. The second line contains m integers N1, N2 … Nm, 1 ≤ Ni ≤ 1 000 000, i = 1, 2 … m, representing the number of coins in each of the m towers
// SAMPLE INPUT
// 2 3 5
// 3 12 113 25714 88888
// OUTPUT
// The standard output contains a string of length m composed of letters A and B. If Asen wins the ith game (no matter how the opponent plays), the ith letter of the string has to be A. When Boyan wins the ith game (no matter how Asen plays), the ith letter of the string has to be B.
// SAMPLE OUTPUT
// ABAAB


#include <bits/stdc++.h>
using namespace std;
int main(){
    int k,l,m;
    cin>>k>>l>>m;

    vector<bool> dp(1000001,0);
    dp[1] = 1;
    dp[k] = 1;
    dp[l] = 1;

    for(int i=2;i<=1000000;i++){
        if(i == k or i==l) continue;
        dp[i] = !(dp[i-1] and ((i-k>=1) ? dp[i-k] : 1) and ((i-l>=1) ? dp[i-l] : 1));
    }

    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        if(dp[n] == 1) cout<<"A";
        else cout<<"B";
    }
    return 0;
}