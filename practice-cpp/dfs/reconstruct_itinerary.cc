
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::deque;
using std::stack;
using std::pair;
using std::make_pair;
using std::cout;
using std::min_element;


class Solution {
public:
    // looks like topogical sort?
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      // ticket => edge, graph => adj-list
      vector<string> tours;
      return tours;
    }
};


int main() {

  Solution sol;

  vector<vector<string>> tickets1 = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
  vector<string> answer1 = {"JFK","MUC","LHR","SFO","SJC"};
  vector<vector<string>> tickets2 = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
  vector<string> answer2 = {"JFK","ATL","JFK","SFO","ATL","SFO"};

  auto result1 = sol.findItinerary(tickets1);
  auto result2 = sol.findItinerary(tickets2);

  for (int i = 0; i < result1.size(); i++) {
    auto res = result1[i];
    if (res != answer1[i]) {
      cout << "ticket 1 failed";
    }
    cout << res << " " ;
  }
  cout << "\n";

  for (auto res : result2) {
    cout << res << " " ;
  }
  cout << "\n";

}