class Solution {
public:
    int findGCD(vector<int>& nums) {
        int a = INT_MIN;
        int b = INT_MAX;
        for(int i =0;i<nums.size();i++){

            // find smallest number
            if(nums[i]  < b){
               b =  nums[i];
            }   

            // find largest number 
            if(nums[i] > a){
                a = nums[i];
            }
        }
       return gcd(a,b);
    }
};