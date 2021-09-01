
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using std::cout;
using std::vector;
using std::unordered_map;
using std::string;
using std::sort;


class Solution {
private:
  vector<int> roots;

  int find(int p) {
    while (p != roots[p]) {
      roots[p] = roots[roots[p]];
      p = roots[p];
    }
    return p;
  }

  void join(int p, int q) {
    int root_p = find(p);
    int root_q = find(q);

    if (root_p == root_q) return;
    roots[root_q] = root_p;
  }

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
      unordered_map<string, int> mail_to_id;

      roots.resize(accounts.size());

      for (int i = 0; i < accounts.size(); ++i) {
        auto account = accounts[i];
        string name = account[0];

        roots[i] = i;

        for (int j = 1; j < account.size(); ++j) {
          string mail = account[j];

          if (mail_to_id.find(mail) != mail_to_id.end()) {
            join(i, mail_to_id[mail]);
          } else {
            mail_to_id[mail] = roots[i];
          }

        }
      }

      unordered_map<int, vector<string>> uid_to_mails;
      for (auto [mail, id] : mail_to_id) {
        // crucial step
        int uid = find(id);
        uid_to_mails[uid].emplace_back(mail);
      }

      vector<vector<string>> results;
      for (auto [id, mails] : uid_to_mails) {
        sort(mails.begin(), mails.end());
        vector<string> tmp = {accounts[id][0]};
        for (auto mail : mails) tmp.emplace_back(mail);
        results.emplace_back(std::move(tmp));
      }

      return results;
    }
};


int main() {

  Solution sol;

  vector<vector<string>> accounts = {{"John","johnsmith@mail.com","john_newyork@mail.com"},
                                     {"John","johnsmith@mail.com","john00@mail.com"},
                                     {"Mary","mary@mail.com"},
                                     {"John","johnnybravo@mail.com"}};
  
  auto results = sol.accountsMerge(accounts);
  // [
  //  ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
  //  ["Mary","mary@mail.com"],
  //  ["John","johnnybravo@mail.com"]]

  for (const auto& res : results) {
    for (string s : res) {
      cout << s << " ";
    }
    cout << "\n";
  }

  accounts = {{"David","David0@m.co","David4@m.co","David3@m.co"},{"David","David5@m.co","David5@m.co","David0@m.co"},{"David","David1@m.co","David4@m.co","David0@m.co"},{"David","David0@m.co","David1@m.co","David3@m.co"},{"David","David4@m.co","David1@m.co","David3@m.co"}};

  results = sol.accountsMerge(accounts);
  // [
  //  ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
  //  ["Mary","mary@mail.com"],
  //  ["John","johnnybravo@mail.com"]]

  for (const auto& res : results) {
    for (string s : res) {
      cout << s << " ";
    }
    cout << "\n";
  }


  return 0;
}