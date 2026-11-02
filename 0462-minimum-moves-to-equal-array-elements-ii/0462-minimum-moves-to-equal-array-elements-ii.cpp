class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(begin(nums),begin(nums)+n/2,end(nums));

        int operation = 0;

        int mid = nums[n/2];

        for(int i=0;i<n;i++){
            operation += abs(nums[i] - mid);
        }
        return operation;
    }
};