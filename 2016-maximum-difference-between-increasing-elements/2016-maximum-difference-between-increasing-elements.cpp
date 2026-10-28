class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min  = INT_MAX;
        int high  = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < min){
                min = nums[i];
            }
            else if( nums[i] > min){
                int ans = nums[i] - min;
                high = max(high,ans);
            }
            
        }
        return high;
    }
};