

#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::string;
using std::vector;
using std::pair;
using std::map;
using std::unordered_map;
using std::priority_queue;
using std::make_pair;
using std::min_element;
using std::cout;



class Solution {
public:
    string frequencySort(string s) {
      // Bucket Sort
      unordered_map<char, int> freqTable;
      for (auto c : s) {
        freqTable[c]++;
      }

      // frequency bucket
      vector<string> bucket(s.size() + 1, "");
      string result;

      for (auto [c, freq] : freqTable) {
        bucket[freq].append(freq, c);
      }

      for (int i = s.size(); i > 0; i--) {
        if (!bucket[i].empty()) {
          result.append(bucket[i]);
        }
      }
        
      return result;
    }

    string frequencySort_v2(string s) {
      // Bucket Sort
      unordered_map<char, int> freqTable;
      for (auto c : s) {
        freqTable[c]++;
      }

      string result;

      // use map as frequency bucket to save memory!
      // somehow really like priority queue
      map<int, string> bucket;

      for (auto [c, freq] : freqTable) {
        bucket[freq].append(freq, c);
      }

      // learn a bit iterator
      for (auto rit = bucket.rbegin(); rit != bucket.rend(); ++rit) {
        result += rit->second;
      }
        
      return result;
    }
};


int main() {

  Solution sol;

  string s = "bcccaa";
  cout << s << "\n";
  auto res = sol.frequencySort_v2(s);
  cout << res << "\n";

  return 0;
}