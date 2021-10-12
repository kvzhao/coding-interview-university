
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
  }
};


int main() {
  Solution sol;
  /// Orz, I dont know how to init these vector of lst ...
  vector<vector<int>> values = {{1,4,5},{1,3,4},{2,6}};
  vector<ListNode*> list(values.size());
  for (int i = 0; i < values.size(); ++i) {
    ListNode* head = *list.data();
    for (int j = 0; j < values[i].size(); ++j) {
      if (j == 0) {
        head = new ListNode(values[i][j]);
        cout << "head = new " << values[i][j] << "\n";
        cout << head << ", " << list[i] << "\n";
      } else {
        head->next = new ListNode(values[i][j]);
        cout << "head->next = new " << values[i][j] << "\n";
        head = head->next;
      }
    }
  }

  // print
  for (int i = 0; i < list.size(); ++i) {
    ListNode* head = list[i];
    while (head != nullptr) {
      cout << head->val << " ";
      head = head->next;
    }
    cout << ",";
  }
  cout << "\n";

  // Input: lists = [[1,4,5],[1,3,4],[2,6]]
  // Output: [1,1,2,3,4,4,5,6]
  return 0;
}