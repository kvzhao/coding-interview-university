
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = 1e9;

        for (auto current : prices) {
            min_price = min(current, min_price);
            int profit = current - min_price;
            max_profit = max(profit, max_profit);
        }
        return max_profit;
    }
};



int main() {

    //You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    //Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

    vector<int> prices;
    int ans, ret;
    Solution sol;

    prices = {7,1,5,3,6,4};
    ans = 5;
    ret = sol.maxProfit(prices);
    if (ret == ans)
    cout << "pass\n";
      else
    cout << "failed, " << ret << "\n";

    prices = {7,6,4,3,1};
    ans = 0;
    ret = sol.maxProfit(prices);
    if (ret == ans)
    cout << "pass\n";
      else
    cout << "failed, " << ret << "\n";

    return 0;
}