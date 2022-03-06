#include <iostream>
#include <queue>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

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
  string line;
  while (getline(cin, line)) {
    int n = stoi(line);
    getline(cin, line);
    auto vec1d = stringToVector(line);
    getline(cin, line);
    auto vec2d = stringTo2DVector(line);
    cout << endl;
  }
  return 0;
}