class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // // Method-1 (by tracking the min buy ans max sell prices at each day)
        // int n = prices.size();

        // vector<int> buy(n);          // to find the min prices to buy stock up to ith day
        // buy[0] = prices[0];

        // for(int i = 1 ; i<n; i++){
        //     buy[i] = min(buy[i-1], prices[i]);
        // }
        
        // vector<int> sell(n);         // to find the max price to sell stock up to ith day
        // sell[n-1] = prices[n-1];

        // for(int i = n-2 ; i>=0 ; i--){
        //     sell[i] = max(sell[i+1], prices[i]);
        // }

        // int max_profit = 0;
        // for(int i = 0 ; i<n ; i++){
        //     max_profit = max(max_profit , sell[i]-buy[i]);       // find the day when the profit is max 
        // }
        // return max_profit;
        // // Method-1 TC - O(n) ans SC - O(n)


        // Method-2 (fnid the maxProfit at each index)

        int maxProfit = 0;
        int sell_price = prices[0];

        for(int i = 1 ; i<prices.size() ; i++){
            int curr_profit = prices[i] - sell_price;  // find the current_maxProfit
            maxProfit = max(maxProfit , curr_profit);   // update the max_profit 
            sell_price = min(sell_price , prices[i]);    // update the selling price
        }
        return maxProfit;
        // Method-2 => TC - O(n) , SC - O(1) 
    }
};