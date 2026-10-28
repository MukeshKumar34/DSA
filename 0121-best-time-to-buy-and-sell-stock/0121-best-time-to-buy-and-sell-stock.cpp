class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int high = 0;

        for(int i=0;i<prices.size();i++){
            if(min > prices[i]){
                min = prices[i];
            }
            else{
                int maxprofit = prices[i] - min;
                high = max(high,maxprofit);
            }
        }
        return high;
    }
};