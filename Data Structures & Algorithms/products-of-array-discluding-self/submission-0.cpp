class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int num0s = 0;
        int idxOf0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                ++num0s;
                idxOf0 = i;
                continue;
            }

            product *= nums[i];
        }

        vector<int> out(nums.size(), 0);
        if (num0s > 1) { return out; }
        if (num0s == 1) { out[idxOf0] = product; return out; }

        for (int i = 0; i < nums.size(); ++i) {
            out[i] = product / nums[i];
        }

        return out;

    }
};
