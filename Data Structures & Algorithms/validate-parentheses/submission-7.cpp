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
            if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                stk.emplace(s[idx]);
            }
            // if (fwdChs.find(s[idx]) != fwdChs.end()) {
            // }

            else {
                if (stk.empty()) return false;
                
                if (s[idx] == ')' && stk.top() != '(') return false;
                if (s[idx] == '}' && stk.top() != '{') return false;
                if (s[idx] == ']' && stk.top() != '[') return false;

                stk.pop();
            }
        }

        return stk.empty();
    }
};
