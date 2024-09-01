#include <unordered_map>

// Definition for singly-linked list.


class Solution {
private:
    unordered_map<ListNode*, bool> visited;
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr) {
            return false;
        }

        if (visited[head]) {
            return true;
        }

        visited[head] = true;
        return hasCycle(head->next);
    }
};
