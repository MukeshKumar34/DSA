class Solution {
public:
    int findMin(vector<int>& nums) {
        // int st=0,end = nums.size()-1;

        // while(st<=end){
        //     int mid = st + (end-st)/2;
        //     if(nums[mid])
        // }
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < ans){
                ans = nums[i];
            }
        }
        return ans;
    }
};