/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 1;
        ListNode* DummyHead = new ListNode();
        DummyHead->next = head;
        ListNode* pointer = DummyHead;
        while(pointer->next!=nullptr){
            pointer = pointer->next;
            length++;
        }
        pointer = DummyHead;
        for(int i = 0; i < length-n-1; i++){
            pointer = pointer->next;
        }
        pointer->next = pointer->next->next;
        return DummyHead->next;
    }
};