class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> kv;
        kv.reserve(nums.size());
        // for (int i = nums.size() - 1; i >= 0; --i) {
        //     kv[nums[i]].push_back(i);
        // }

        // for (int i = 0; i < nums.size(); ++i) {
        //     int complement = target - nums[i];
        //     kv[nums[i]].pop_back();
        //     if(kv[nums[i]].empty()) { kv.erase(nums[i]); }

        //     auto it = kv.find(complement);
        //     if (it != kv.end()) { // found complement
        //         return {min(it->second.back(), i), max(it->second.back(), i)};
        //     }
        // }

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
