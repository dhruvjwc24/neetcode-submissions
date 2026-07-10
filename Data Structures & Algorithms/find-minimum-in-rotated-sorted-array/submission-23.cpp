class Solution {
public:
    int findMin(vector<int>& nums) {
        int lower = 0;
        int upper = nums.size() - 1;

        while (lower < upper) {
            int mid = lower + (upper - lower) / 2;

            if (nums[mid] > nums[upper]) {
                lower = mid + 1;
            } else {
                upper = mid;
            }
        }

        return nums[lower];
    }
};