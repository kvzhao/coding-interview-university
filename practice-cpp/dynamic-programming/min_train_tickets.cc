

#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::min;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {


      return -1; 
    }
};


int main() {

  Solution sol;

  vector<int> days = {1,4,6,7,8,20}, costs = {2,7,15};
  const int ans1 = 11;

  int p1 = sol.mincostTickets(days, costs);

  days = {1,2,3,4,5,6,7,8,9,10,30,31}, costs = {2,7,15};
  int p2 = sol.mincostTickets(days, costs);
  const int ans2 = 17;

  if (p1 == ans1 and p2 == ans2) {
    cout << "Passed\n";
  } else {
    cout << p1 << ", " << p2 << "\n";
  }

  return 0;
}