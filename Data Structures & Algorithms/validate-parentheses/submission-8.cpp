class Solution {
public:
    bool isValid(string s) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        if (s.size() % 2 != 0) return false;
        stack<char> stk;

        for (int idx = 0; idx < s.size(); ++idx) {
            if (s[idx] == '(' || s[idx] == '{' || s[idx] == '[') {
                stk.emplace(s[idx]);
            }

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
