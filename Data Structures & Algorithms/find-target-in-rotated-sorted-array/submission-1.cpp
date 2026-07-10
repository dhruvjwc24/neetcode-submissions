class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lower = 0;
        int upper = nums.size() - 1;

        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;

            if (nums[mid] == target) return mid;

            if (nums[lower] <= nums[mid]) { // left half is sorted
                if (nums[lower] <= target && target < nums[mid]) { // in that range
                    upper = mid - 1;
                } else {
                    lower = mid + 1;
                }
            } else { // right half is sorted
                if (nums[mid] < target && target <= nums[upper]) { // in that range
                    lower = mid + 1;
                } else {
                    upper = mid - 1;
                }
            }
        }

        return -1;
    }
};
