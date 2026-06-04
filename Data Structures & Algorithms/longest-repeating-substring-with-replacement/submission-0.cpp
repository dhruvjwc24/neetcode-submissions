class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int max_freq = 0;
        int best = 0;

        vector<int> freqs(26, 0);
        
        for (int r = 0; r < s.size(); ++r) {
            ++freqs[s[r] - 'A'];
            max_freq = max(max_freq, freqs[s[r] - 'A']);

            while (r - l + 1 - max_freq > k) {
                --freqs[s[l] - 'A'];
                ++l;
            }

            best = max(best, r - l + 1);

        }

        return best;

    }
};
