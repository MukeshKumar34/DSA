class Solution {
public:

static bool compare(int a,int b){
    return (to_string(a) + to_string(b)   > to_string(b) + to_string(a));
}
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(),nums.end(),compare);
 if (nums[0] == 0) return "0";
        for(auto i:nums){
            ans += to_string(i);
        }
return ans;

    }
};