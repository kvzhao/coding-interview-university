
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
  int minMeetingRooms(vector<vector<int>>& intervals) {
    if (intervals.empty()) return true;
    sort(intervals.begin(), intervals.end());

    return 0;
  }
};

int main() {
  /*
  Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
  */
  vector<vector<int>> intervals;
  int ans, ret;

  Solution sol;
  intervals = {{0,30},{5,10},{15,20}};
  ans = 2;

  ret = sol.minMeetingRooms(intervals);
  if (ans != ret) cout << "failed\n";
  else cout << "passed\n";

  intervals = {{7,10},{2,4}};
  ans = 1;
  ret = sol.minMeetingRooms(intervals);
  if (ans != ret) cout << "failed\n";
  else cout << "passed\n";

  return 0;
}