class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> underlyingContainer;
        vector<int> result(temperatures.size(), 0);
        underlyingContainer.reserve(temperatures.size());
        stack<int, vector<int>> stk(std::move(underlyingContainer));

        for (int idx = 0; idx < temperatures.size(); ++idx) {
            if (stk.empty()) {
                stk.push(idx); 
            }

            while (!stk.empty() && temperatures[idx] > temperatures[stk.top()]) {
                result[stk.top()] = idx - stk.top();
                stk.pop();
            }

            stk.push(idx);
        }

        return result;
    }
};
