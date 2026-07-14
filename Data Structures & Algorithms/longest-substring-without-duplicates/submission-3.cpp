class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int maxLen = 0;
        int left = 0; 
        int right = 0;

        for (; right < s.size(); ++right) {
            auto it = charSet.find(s[right]);
            if (it == charSet.end()) { // not found in set
                charSet.insert(s[right]);
                maxLen = max(maxLen, right - left + 1);
            } else {
                for (; left < right; ++left) {
                    if (s[left] == s[right]) {
                        ++left;
                        break;
                    }

                    charSet.erase(s[left]);
                }
            }
        }
        return maxLen;

    }
};
