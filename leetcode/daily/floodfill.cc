#include "../leetcode_utility.hpp"

using namespace std;

class Solution {
public:
  vector<vector<int>> floodFillBFS(vector<vector<int>> &image, int sr, int sc,
                                   int newColor) {
    int oldColor = image[sr][sc];
    if (oldColor == newColor)
      return image;

    const vector<pair<int, int>> dirs = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    deque<pair<int, int>> queue{{sr, sc}};

    while (!queue.empty()) {

      auto [row, col] = queue.front();
      queue.pop_front();
      image[row][col] = newColor;

      for (const auto &[R, C] : dirs) {
        int r = row + R;
        int c = col + C;
        if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
            image[r][c] != oldColor)
          continue;
        queue.emplace_back(make_pair(r, c));
      }
    }
    return image;
  }

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                int newColor) {
    if (newColor != image[sr][sc]) {
      fill(image, sr, sc, newColor, image[sr][sc]);
    }
    return image;
  }

protected:
  void fill(vector<vector<int>> &image, int r, int c, int newColor,
            int oldColor) {

    if (r < 0 || r >= image.size() || c < 0 || c >= image[0].size() ||
        image[r][c] != oldColor)
      return;

    image[r][c] = newColor;
    fill(image, r + 1, c, newColor, oldColor);
    fill(image, r - 1, c, newColor, oldColor);
    fill(image, r, c + 1, newColor, oldColor);
    fill(image, r, c - 1, newColor, oldColor);
  }
};

int main() {
  string line;
  Solution sol;
  while (getline(cin, line)) {
    vector<vector<int>> image = stringToIntegerVector2D(line);
    getline(cin, line);
    int sr = stoi(line);
    getline(cin, line);
    int sc = stoi(line);
    getline(cin, line);
    int newColor = stoi(line);

    auto ret = sol.floodFillBFS(image, sr, sc, newColor);

    cout << integerVector2DToString(ret) << endl;
  }
  return 0;
}