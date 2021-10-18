// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {

        int lo = 1, hi = n;
        // [1, 2, 3, x, x, x, x], n = 7
        
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            
            if (isBadVersion(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
            
        }
        
        return lo;
    }
};