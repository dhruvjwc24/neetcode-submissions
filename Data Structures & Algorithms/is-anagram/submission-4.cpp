class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;

        for (char ch : s) {
            ++um1[ch];
        }

        for (char ch : t) {
            ++um2[ch];
        }

        return um1 == um2;
    }
};
