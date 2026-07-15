class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int maxLen = 0;
        int left = 0; 
        int right = 0;

        for (; right < s.size(); ++right) {
            auto it = charMap.find(s[right]);
            if (it != charMap.end() && it->second >= left) { // not found in map or map is outdated
                left = it->second + 1;
            }
            
            charMap[s[right]] = right;
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;

    }
};
