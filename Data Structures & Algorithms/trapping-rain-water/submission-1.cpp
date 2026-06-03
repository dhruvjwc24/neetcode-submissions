class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = 0;
        int rmax = 0;
        int l = 0;
        int r = height.size() - 1;

        int count = 0;

        while (l < r) {
            if (height[l] < height[r]) {
                lmax = max(lmax, height[l]);
                count += lmax - height[l];
                ++l;
            } else {
                rmax = max(rmax, height[r]);
                count += rmax - height[r];
                --r;
            }
        }

        return count;
    }
};
