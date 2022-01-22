#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
  bool possible(const vector<int> &piles, int h, int k)
  {
    int times = 0;
    for (int p : piles)
      times += (p - 1) / k + 1;

    return times <= h;
  }

public:
  int minEatingSpeed(vector<int> &piles, int h)
  {
    int lo = 1, hi = *max_element(piles.begin(), piles.end());

    while (lo < hi)
    {
      int mid = lo + (hi - lo) / 2;

      if (!possible(piles, h, mid))
      {
        lo = mid + 1;
      }
      else
      {
        hi = mid;
      }
    }
    return lo;
  }
};

int main()
{

  Solution sol;

  vector<int> piles;
  int h = 0, ans = 0, ret = 0;

  piles = {3, 6, 7, 11};
  h = 8;
  ret = sol.minEatingSpeed(piles, h);
  ans = 4;
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  piles = {30, 11, 23, 4, 20};
  h = 5;
  ret = sol.minEatingSpeed(piles, h);
  ans = 30;
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";

  piles = {30, 11, 23, 4, 20};
  h = 6;
  ans = 23;
  ret = sol.minEatingSpeed(piles, h);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";
  piles = {332484035, 524908576, 855865114, 632922376, 222257295, 690155293, 112677673, 679580077, 337406589, 290818316, 877337160, 901728858, 679284947, 688210097, 692137887, 718203285, 629455728, 941802184};
  h = 823855818;
  ans = 14;
  ret = sol.minEatingSpeed(piles, h);
  if (ans != ret)
    cout << "Failed " << ret << "\n";
  else
    cout << "Passed\n";
}