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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        head = dummy;
        ListNode* leftPointer = head->next;
        ListNode* rightPointer = head->next;
        ListNode* dummyHead = head;
        int count = 1;
        while(rightPointer!=nullptr && rightPointer->next!=nullptr){
            rightPointer = rightPointer->next;
            count++;
            if(count==k){
                ListNode* dummyTail = rightPointer->next;
                ListNode* dummyRight = rightPointer;
                ListNode* pointer = leftPointer;
                cout << leftPointer->val << endl;
                while(leftPointer!=rightPointer){
                    pointer = leftPointer;
                    while(pointer->next!=rightPointer){
                        pointer = pointer->next;
                    }
                    cout << leftPointer->val << pointer->val << endl;
                    rightPointer->next = pointer;
                    rightPointer = pointer;
                }
                dummyHead->next = dummyRight;
                pointer->next = dummyTail;
                dummyHead = pointer;
                count = 1;
                rightPointer = dummyTail;
                leftPointer = dummyTail;
            }
        }
        return dummy->next;
    }
};