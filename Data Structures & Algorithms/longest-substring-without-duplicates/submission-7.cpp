class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;

        int maxLen = 0;
        int left = 0;

        int n = s.size();

        for (int right = 0; right < n; ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left++]);
            }

            charSet.insert(s[right]);
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;

    }
};
