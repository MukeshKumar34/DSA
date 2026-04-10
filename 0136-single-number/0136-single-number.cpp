class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i=0;i<n;i++){
            count = count ^ nums[i];
        }
        return count;
    }
};