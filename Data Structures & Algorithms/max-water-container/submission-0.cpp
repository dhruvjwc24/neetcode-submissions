class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0;
        int second = height.size() - 1;
        int max_area = second * min(height[first], height[second]);

        while (first < second) {
            if (height[first] < height[second]) { ++first; } 
            else { --second; }
            max_area = max(max_area, (second - first) * min(height[first], height[second]));
        }
        return max_area;
    }
};