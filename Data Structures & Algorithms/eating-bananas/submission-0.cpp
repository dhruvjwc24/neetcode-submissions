class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long sum = 0;
        int maxSize = 0;

        for (int size : piles) {
            sum += size;
            maxSize = max(maxSize, size);
        }

        int lower = sum / h + (sum % h != 0);
        int upper = maxSize;

        int bsf = upper;

        while (lower <= upper) {
            int mid = lower + (upper - lower) / 2;

            int candidateTime = 0;
            for (int size : piles) {
                candidateTime += size / mid + (size % mid != 0);
            }

            if (candidateTime <= h) { 
                bsf = min(bsf, mid);
                upper = mid - 1;
            }

            else {
                lower = mid + 1;
            }
        }

        return bsf;
    }
};
