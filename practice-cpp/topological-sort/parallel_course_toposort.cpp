#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumSemesters(int n, vector<vector<int>> &relations) {
    // abj mat
    unordered_map<int, vector<int>> graph;
    vector<int> indeg(n + 1, 0);
    for (auto &ret : relations) {
      graph[ret[0]].emplace_back(ret[1]);
      ++indeg[ret[1]];
    }

    // DFS

    deque<int> queue;
    for (int i = 1; i <= n; ++i) {
      if (indeg[i] == 0)
        queue.emplace_back(i);
    }

    int semesters = 0;
    int course_taken = 0;
    while (!queue.empty()) {
      int size = queue.size();
      ++semesters;

      for (int i = 0; i < size; ++i) {
        int node = queue.front();
        queue.pop_front();
        ++course_taken;

        for (auto &neighbor : graph[node]) {
          --indeg[neighbor];
          if (indeg[neighbor] == 0) {
            queue.emplace_back(neighbor);
          }
        }
      }
    }

    return course_taken == n ? semesters : -1;
  }
};

void trimLeftTrailingSpaces(string &input) {
  input.erase(input.begin(), find_if(input.begin(), input.end(),
                                     [](int ch) { return !isspace(ch); }));
};

void trimRightTrailingSpaces(string &input) {
  input.erase(
      find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); })
          .base(),
      input.end());
}

//[1,2]
vector<int> stringToVector(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);

  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<int> ret;

  ss.str(input);
  getline(ss, item, ',');
  ret.emplace_back(stoi(item));

  while (true) {
    if (!getline(ss, item, ',')) {
      break;
    }
    trimLeftTrailingSpaces(item);
    ret.emplace_back(stoi(item));
  }

  return move(ret);
}

//[[1,2], [2,3]]
vector<vector<int>> stringTo2DVector(string input) {
  trimLeftTrailingSpaces(input);
  trimRightTrailingSpaces(input);
  input = input.substr(1, input.length() - 2);

  string item;
  stringstream ss;
  vector<vector<int>> rets;

  size_t end = 0;
  while (true) {
    end = input.find(']') + 1;
    string segment = input.substr(0, end);
    auto ret = stringToVector(segment);
    rets.emplace_back(ret);
    if (end + 1 > input.length())
      break;
    input = input.substr(end + 1, input.length());
  }

  return move(rets);
}

int main() {

  Solution sol;
  string line;
  while (getline(cin, line)) {

    int n = stoi(line);
    getline(cin, line);
    vector<vector<int>> relations = stringTo2DVector(line);

    int ret = sol.minimumSemesters(n, relations);

    cout << ret << endl;
  }
  return 0;
}