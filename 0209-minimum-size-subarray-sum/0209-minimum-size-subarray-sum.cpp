class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int final = INT_MAX;
        int left = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            while(sum >= target) {
                int length = i - left + 1;

                final = min(final, length);

                sum -= nums[left];
                left++;
            }
        }

        if(final == INT_MAX) return 0;

        return final;
    }
};