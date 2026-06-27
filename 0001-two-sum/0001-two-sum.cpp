class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // If complement is found, return indices
            if (mp.find(complement) != mp.end()) {
                return {mp[complement], i};
            }

            // Store current number with its index
            mp[nums[i]] = i;
        }

        return {}; // fallback (problem guarantees one solution)
    }
};
