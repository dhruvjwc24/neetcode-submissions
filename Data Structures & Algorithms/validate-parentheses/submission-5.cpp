class Solution {
public:
    bool isValid(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (s.size() % 2 != 0) return false;
        stack<char> stk;
        set<char> fwdChs = {'(', '{', '['};
        set<char> bwdChs = {')', '}', ']'};
        unordered_map<char, char> pam = {{')', '('}, {'}', '{'}, {']', '['}};

        for (int idx = 0; idx < s.size(); ++idx) {
            // if the char at idx is a fwd char just add to stack
            if (fwdChs.find(s[idx]) != fwdChs.end()) {
                stk.emplace(s[idx]);
            }

            if (bwdChs.find(s[idx]) != bwdChs.end()) {
                if (stk.empty() || stk.top() != pam[s[idx]]) return false;
                stk.pop();
            }
        }

        if (!stk.empty()) return false;

        return true;
    }
};
