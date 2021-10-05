
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct comparator {
  bool operator() (vector<int>& v1, vector<int>& v2) {
    return v1[0] < v2[0];
  }
} MyComparator;

class Solution {
public:
  bool canAttendMeetings(vector<vector<int>>& intervals) {

    if (intervals.empty()) return true;

    sort(intervals.begin(), intervals.end(), MyComparator);

    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[i][0] < intervals[i-1][1]) return false;
    }

    return true;
  }
};

int main() {
  /*
  Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.
  */
  vector<vector<int>> intervals;
  bool ans, ret;

  Solution sol;
  intervals = {{0,30},{5,10},{15,20}};
  ans = false;

  ret = sol.canAttendMeetings(intervals);
  if (ans != ret) cout << "failed\n";
  else cout << "passed\n";

  intervals = {{7,10},{2,4}};
  ans = true;
  ret = sol.canAttendMeetings(intervals);
  if (ans != ret) cout << "failed\n";
  else cout << "passed\n";

  return 0;
}