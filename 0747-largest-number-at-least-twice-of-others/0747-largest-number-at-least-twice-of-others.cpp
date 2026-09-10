class Solution {
public:
    int dominantIndex(vector<int>& nums) {
     int max = INT_MIN;
     int maxindex = 0;

     for(int i=0;i<nums.size();i++){
        if(max < nums[i]){
            max = nums[i];
            maxindex =i;
        }
     }
     
       for(int i=0;i<nums.size();i++){
        if(i != maxindex && max < 2*nums[i]){
            return -1;
        }
       }
     return maxindex;
     
    }
};