class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tes(nums.begin(), nums.end());
        int longest_sequence = 0;
        for (auto num : nums) {
            auto it = tes.find(num - 1); 
            if (it == tes.end()) { // so it is a start of a sequence
                int off = 0;
                while (true) {
                    it = tes.find(num + off);
                    if (it == tes.end()) { break; }
                    ++off;
                }

                longest_sequence = off > longest_sequence ? off : longest_sequence;
            }
        }

        return longest_sequence;
    }
};
