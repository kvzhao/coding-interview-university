
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash;
        
        for (const auto& n : nums) {
            if (hash.find(n) != hash.end()) {
                return true;
            }
            hash.insert(n);
        }
        return false;
    }
};
