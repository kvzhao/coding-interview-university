
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int num_neg =0;
        for (auto n : nums) {
            if (n == 0)  return 0;
            
            if (n < 0) ++num_neg;
        }
        if (num_neg %2 == 0) return 1;
        else return -1;
    }
};
