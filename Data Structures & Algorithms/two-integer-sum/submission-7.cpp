class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> kv;
        kv.reserve(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            auto it = kv.find(complement);
            if (it != kv.end()) {
                return {min(it->second, i), max(it->second, i)};
            }
            kv[nums[i]] = i;
        }

        return {};
    }
};
