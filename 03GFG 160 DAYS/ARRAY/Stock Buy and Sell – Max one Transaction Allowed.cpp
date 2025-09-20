#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        int min_prices = INT_MAX;
        int profit = 0;
        for(int price : prices){
            min_prices = min(min_prices,price );
            profit = max(profit,price-min_prices);
        }
        return profit;
        
    }
};
