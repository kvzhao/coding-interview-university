
#include <string>
#include <vector>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::unordered_map;
using std::multiset;
using std::deque;
using std::stack;
using std::pair;
using std::make_pair;
using std::cout;
using std::min_element;
using std::reverse;


class Solution {
public:
    // kinda topological sort, dfs and backtracking
    vector<string> findItinerary(vector<vector<string>>& tickets) {
      // ticket => edge, graph => adj-list
    vector<string> tours;

    // node: out-going edge
    unordered_map<string, multiset<string>> graph;
    if (tickets.size() == 0) {
      return tours;
    }
    // build graph
    for (const auto& eachTicket : tickets) {
      graph[eachTicket[0]].insert(eachTicket[1]);
    }

    stack<string> dfs;
    dfs.emplace("JFK");

    // elegant method but don't fully understand
    while (!dfs.empty()) {
      auto topAirport = dfs.top();

      if (graph[topAirport].empty()) {

        tours.emplace_back(topAirport);
        dfs.pop();

      } else {

        dfs.emplace(*(graph[topAirport].begin()));
        graph[topAirport].erase(graph[topAirport].begin());

      }

    }
    
    reverse(tours.begin(), tours.end());


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

  if (!(result1.size() == answer1.size() and result2.size() == answer2.size())) {
    cout << "Failed, size not equal\n";
    return 0;
  }

  bool pass1 = true, pass2 = true;
  for (int i = 0; i < result1.size(); i++) {
    auto res = result1[i];
    if (res != answer1[i]) {
      cout << "1: res[i] = " << res << ", ans[i] = " << answer1[i] << "\n"; 
      pass1 = false;
      break;
    }
  }

  for (int i = 0; i < result2.size(); i++) {
    auto res = result2[i];
    if (res != answer2[i]) {
      cout << "2: res[i] = " << res << ", ans[i] = " << answer2[i] << "\n"; 
      pass2 = false;
      break;
    }
  }

  if (pass1 and pass2) {
    cout << "Passed\n";
  } else {
    cout << "Failed\n";
  }

  return 0;
}