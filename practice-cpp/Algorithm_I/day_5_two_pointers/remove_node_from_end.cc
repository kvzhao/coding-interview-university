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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        // remove one node
        slow->next = slow->next->next;
        return head;
    }
};


int main() {

    Solution sol;

    vector<int> values = {1,2,3,4,5};
    int n = 2;
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    // Output: [1,2,3,5]
    current = sol.removeNthFromEnd(head, n);
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << "\n";

    return 0;
}