class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> um;
        for (char ch : s) {
            ++um[ch];
        }

        for (char ch : t) {
            --um[ch];
        } 

        for (auto& p : um) {
            if (p.second != 0) { return false; }
        }
        return true;
    }
};
