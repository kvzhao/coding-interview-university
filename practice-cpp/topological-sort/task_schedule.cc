
#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>

using std::vector;
using std::unordered_map;
using std::queue;
using std::cout, std::endl;


class TaskSchedulingOrder{
public:
// for calling method
static vector<int> findOrder(int tasks, const vector<vector<int>>& prerequisites) {
  vector<int> sorted_order;
  if (tasks <= 0) return sorted_order;

  // build graph
  unordered_map<int, vector<int>> graph;
  unordered_map<int, int> in_degree;
  for (int i = 0; i < tasks; i++) {
    graph[i] = vector<int>();
    in_degree[i] = 0;
  }

  for (int i = 0; i < prerequisites.size(); i++) {
    int parent = prerequisites[i][0], child = prerequisites[i][1];
    in_degree[child]++;
    graph[parent].emplace_back(child);
  }
  queue<int> sources;
  for (auto [vertex, count]: in_degree) {
    if (count == 0) {
      sources.emplace(vertex);
    }
  }

  while (!sources.empty()) {
    int vertex = sources.front();
    sources.pop();
    sorted_order.emplace_back(vertex);

    auto children = graph[vertex];
    for (auto child : children) {
      if (--in_degree[child] == 0) {
        sources.push(child);
      }
    }
  }

  if (sorted_order.size () != tasks) {
    return vector<int>();
  }

  return sorted_order;
}

};

int main() {

  int n = 6;
  vector<vector<int>> tasks{
    {2, 5}, {0, 5}, {0, 4}, {1, 4}, {3, 2}, {1, 3}
  };

  auto res = TaskSchedulingOrder::findOrder(n, tasks);

  for (auto r : res) {
    cout << r << " ";
  }
  cout << endl;

  return 0;
}
