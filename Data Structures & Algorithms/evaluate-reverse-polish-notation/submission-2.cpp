class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> underlyingContainer(tokens.size());
        stack<int, vector<int>> stk(std::move(underlyingContainer));

        int tokA, tokB;

        for (string& tok : tokens) {
            if (tok == "+") {
                // + sequence
                tokB = stk.top();
                stk.pop();
                tokA = stk.top();
                stk.pop();
                stk.push(tokA + tokB);
            } 
            
            else if (tok == "-") {
                // - sequence
                tokB = stk.top();
                stk.pop();
                tokA = stk.top();
                stk.pop();
                stk.push(tokA - tokB);
            }

            else if (tok == "*") {
                // * sequence
                tokB = stk.top();
                stk.pop();
                tokA = stk.top();
                stk.pop();
                stk.push(tokA * tokB);
            }

            else if (tok == "/") {
                // / sequence
                tokB = stk.top();
                stk.pop();
                tokA = stk.top();
                stk.pop();
                stk.push(tokA / tokB);
            }

            else {
                stk.push(stoi(tok));
            }
        }

        return stk.top();
    }
};
