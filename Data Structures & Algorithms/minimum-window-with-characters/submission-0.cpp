class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        vector<int> have(128, 0);
        vector<int> need(128, 0);

        int required = 0;
        int formed = 0;

        int best_len = INT_MAX;
        int best_start = 0;
        int left = 0;

        for (char ch : t) {
            if (need[ch]++ == 0) required++;
        }

        for (int right = 0; right < s.size(); ++right) {
            char ch = s[right];
            have[ch]++;
            if (need[ch] > 0 && have[ch] == need[ch]) {
                formed++;
            }

            while (formed == required) {
                if (right - left + 1 < best_len) {
                    best_len = right - left + 1;
                    best_start = left;
                }

                char l = s[left++];
                have[l]--;
                if (need[l] > 0 && have[l] < need[l]) {
                    formed--;
                }
            }
        }

        return best_len == INT_MAX ? "" : s.substr(best_start, best_len);
    }
};
