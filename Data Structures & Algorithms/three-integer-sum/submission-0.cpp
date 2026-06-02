class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), less<int>()); // sort in ascending order
        vector<vector<int>> out;
        
        int i = 0;
        while (i < nums.size() - 2) {
            int target = -nums[i];

            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                if (nums[j] + nums[k] == target) {
                    out.push_back({nums[i], nums[j], nums[k]}); ++j; --k;
                    while (j < k && nums[j] == nums[j - 1]) { ++j; };
                    while (k > j && nums[k] == nums[k + 1]) { --k; };
                } 
                
                else if (nums[j] + nums[k] < target) { ++j; }
                else { --k; }

            }
            ++i;
            while (i < nums.size() - 2 && nums[i] == nums[i - 1]) { ++i; }
        }

        return out;
    }
};
