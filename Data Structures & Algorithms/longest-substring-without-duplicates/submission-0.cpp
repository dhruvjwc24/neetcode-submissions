class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int best = 0;
        int l = 0;
        int r = 0;

        unordered_set<char> uniques;
        
        while (r < s.size()) {
            auto it = uniques.find(s[r]);
            if (it == uniques.end()) {
                uniques.insert(s[r]);
                best = max((int)uniques.size(), best);
                ++r;
            } else {
                while (s[l] != s[r]) {
                    uniques.erase(s[l++]);
                }
                ++l; ++r;
            }
        }

        return best;
    }
};
