class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int minel = INT_MAX;

        for(int i=0;i<n;i++){
            if(nums[i] < minel){
                 minel = nums[i];
            }   
        }

        for(int i=0;i<n;i++){
            sum +=nums[i];
        }

        int result = sum - (n * minel);
        return result;
    }
};