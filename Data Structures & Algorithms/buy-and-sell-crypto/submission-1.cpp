class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bsf = 0;
        int msf = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            bsf = max(prices[i] - msf, bsf);
            msf = min(prices[i], msf);
        }

        return bsf;
    }
};
