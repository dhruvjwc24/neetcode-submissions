class Solution {
public:
    int findMin(vector<int> &nums) {
        int lower = 0; int upper = nums.size() - 1;
        int minimum = nums[upper];

        while (lower <= upper) {
            if (nums[lower] <= nums[upper]) return nums[lower];

            int mid = lower + (upper - lower) / 2;

            if (nums[mid] < nums[lower]) { // break is to the left
                upper = mid;
            } else {
                lower = mid + 1;
            }
        }
        return minimum;
    }
};
