// The Bad Luck Island is inhabited by three kinds of species: r rocks, s scissors and p papers.At some 
// moments of time two random individuals meet (all pairs of individuals can meet equiprobably), and if
//  they belong to different species, then one individual kills the other one: a rock kills scissors, 
// scissors kill paper,and paper kills a rock. Your task is to determine for each species what is the 
// probability that this species will be the only one to inhabit this island after a long enough period 
// of time.

// Input
// The single line contains three integers r, s and p (1 ≤ r, s, p ≤ 100) — the original number of individuals
//  in the species of rock, scissors and paper, respectively.

// Output
// Print three space-separated real numbers: the probabilities, at which the rocks, the scissors and the 
// paper will be the only surviving species, respectively. The answer will be considered correct if the
// relative or absolute error of each number doesn't exceed 10 - 9.

// Examples
// Input
// 2 2 2
// Output
// 0.333333333333 0.333333333333 0.333333333333


#include<bits/stdc++.h> 
using namespace std; 
#define ld long double
#define ll long long
ld dp[105][105][105];

ld fr(int r, int s, int p) {
	if(r == 0 or s == 0) return 0.0;
	if(p == 0) return 1.0;
	if(dp[r][s][p] > -0.9) {
		return dp[r][s][p];
	}
	ld total = r*s + s*p + p*r;
	ld result = 0.0;
	result += fr(r-1,s,p) * ((r*p)/total) ; 
	result += fr(r,s-1,p) * ((r*s)/total) ;
	result += fr(r,s,p-1) * ((s*p)/total) ;
	return dp[r][s][p] = result;
}

ld fs(int r, int s, int p) {
	if(s == 0 or p == 0) return 0.0;
	if(r == 0) return 1.0;
	if(dp[r][s][p] > -0.9) {
		return dp[r][s][p];
	}
	ld total = r*s + s*p + p*r;
	ld result = 0.0;
	result += fs(r-1,s,p) * ((r*p)/total) ; 
	result += fs(r,s-1,p) * ((r*s)/total) ;
	result += fs(r,s,p-1) * ((s*p)/total) ;
	return dp[r][s][p] = result;
}

ld fp(int r, int s, int p) {
	if(p == 0 or r == 0) return 0.0;
	if(s == 0) return 1.0;
	if(dp[r][s][p] > -0.9) {
		return dp[r][s][p];
	}
	ld total = r*s + s*p + p*r;
	ld result = 0.0;
	result += fp(r-1,s,p) * ((r*p)/total) ; 
	result += fp(r,s-1,p) * ((r*s)/total) ;
	result += fp(r,s,p-1) * ((s*p)/total) ;
	return dp[r][s][p] = result;
}
int main(){
  ll r,s,p;
	cin>>r>>s>>p;
	memset(dp, -1.0, sizeof dp);
	ld ans_r = fr(r,s,p);
	memset(dp, -1.0, sizeof dp);
	ld ans_s = fs(r,s,p);
	memset(dp, -1.0, sizeof dp);
	ld ans_p = fp(r,s,p);
	cout<<ans_r<<" "<<ans_s<<" "<<ans_p; 
  return 0;
}