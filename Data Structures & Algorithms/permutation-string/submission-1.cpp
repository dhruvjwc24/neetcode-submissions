class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> freqCount1(26, 0);
        vector<int> freqCount2(26, 0);

        for (char& ch : s1) ++freqCount1[ch - 'a'];

        int start = 0;
        int end = 0;

        for (; end < s1.size(); ++end) {
            ++freqCount2[s2[end] - 'a'];
        }

        while (true) {
            if (freqCount1 == freqCount2) return true;
            if (end == s2.size()) break;
            --freqCount2[s2[start++] - 'a'];
            ++freqCount2[s2[end++] - 'a'];
        }

        return false;
    }
};
