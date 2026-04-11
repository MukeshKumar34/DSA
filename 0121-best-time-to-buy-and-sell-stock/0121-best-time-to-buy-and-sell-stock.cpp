class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int high = 0;
        for(int i=0;i<prices.size();i++){
            if(prices[i] < min){
                min = prices[i];
            }
            else{
                int profit = prices[i] - min;
                high =max(high,profit);
            }
        }
        return high;
    }
};