

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;


    return result;
  }
};


int main() {
  /*
    You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi]
    represent the start and the end of the ith interval and intervals is sorted in ascending order by starti.
    You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
    Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals
    (merge overlapping intervals if necessary).
    Return intervals after the insertion.

    0 <= intervals.length <= 104
    intervals[i].length == 2
    0 <= starti <= endi <= 105
    intervals is sorted by starti in ascending order.
    newInterval.length == 2
    0 <= start <= end <= 105
  */

  vector<vector<int>> intervals, answer;
  vector<int> newInterval;
  

  intervals = {{1,3},{6,9}}, newInterval = {2,5};
  answer = {{1,5},{6,9}};

  intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}}, newInterval = {4,8};
  answer = {{1,2},{3,10},{12,16}};

  intervals = {}, newInterval = {5,7};
  answer = {{5,7}};

  intervals = {{1,5}}, newInterval = {2,3};
  answer = {{1,5}};

  intervals = {{1,5}}, newInterval = {2,7};
  answer = {{1,7}};

  return 0;
}