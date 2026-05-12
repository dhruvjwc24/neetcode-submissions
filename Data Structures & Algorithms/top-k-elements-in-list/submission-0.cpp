class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> pam;
        pam.reserve(nums.size());
        for (auto num : nums) {
            ++pam[num];
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;

        for (auto& it : pam) {
            minpq.push({it.second, it.first});
            if (minpq.size() > k) {
                minpq.pop();
            }
        }

        vector<int> out;
        out.reserve(k);
        while (!minpq.empty()) {
            out.emplace_back(minpq.top().second);
            minpq.pop();
        }

        return out;

    }
};
