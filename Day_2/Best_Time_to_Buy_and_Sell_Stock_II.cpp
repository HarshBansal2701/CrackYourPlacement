class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Method 
        // when the price of stock in current day is higher then previous day => buy and sell it 

        int profit = 0;
        for(int i = 1 ; i<prices.size(); i++){
            if(prices[i]> prices[i-1]){
                profit += (prices[i]-prices[i-1]);
            }
        }
        return profit;

        // Method TC => O(n)
    }
};