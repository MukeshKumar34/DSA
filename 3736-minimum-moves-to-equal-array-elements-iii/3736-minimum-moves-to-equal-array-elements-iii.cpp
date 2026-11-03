
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int operation = 0;
        int maxele = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {
            maxele = max(maxele, nums[i]);
        }

        for(int i = 0; i < nums.size(); i++) {
            operation += maxele - nums[i];
        }

        return operation;
    }
};
