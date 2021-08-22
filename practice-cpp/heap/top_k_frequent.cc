
#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::pair;
using std::unordered_map;
using std::priority_queue;
using std::make_pair;
using std::min_element;
using std::cout;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      vector<int> result(k);
      unordered_map<int, int> freqTable;
      for (auto n : nums) {
        freqTable[n] ++;
      }

      /*
        The following coding techniques needed picking up
        or easier version priority_queue<pair<int, int>> // (freq, num)
      */
      // initialise a heap with most frequent elements at the top
      auto comp = [&freqTable](int n1, int n2) {
        return freqTable[n1] > freqTable[n2];
      };
      priority_queue<int, vector<int>, decltype(comp)> heap(comp);

      for (auto p : freqTable) {
        heap.push(p.first);
        if (heap.size() > k) {
          heap.pop();
        }
      }

      for (int i = k - 1; i >= 0; i--) {
        result[i] = heap.top();
        heap.pop();
      }

      return result;
    }
};



int main() {

  Solution sol;

  vector<int> nums = {1,1,1,2,2,3};
  int k = 2;

  auto res = sol.topKFrequent(nums, k);

  for (auto r : res) {
    cout << r << " ";
  }
  cout << "\n";


  return 0;
}