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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* leftPointer = head;
        ListNode* rightPointer = head;
        for(int i = 0; i < left-1; i++){
            leftPointer = leftPointer->next;
        }
        for(int i = 0; i < right-1; i++){
            rightPointer = rightPointer->next;
        }
        ListNode* tail = rightPointer->next;
        cout << leftPointer->val<< endl;
        cout << rightPointer->val << endl;
        ListNode* r = rightPointer;
        while(leftPointer!=rightPointer){
            ListNode* pointer = leftPointer;
            while(pointer->next!=rightPointer){
                pointer = pointer->next;
            }
            rightPointer->next = pointer;
            rightPointer = rightPointer->next;
        }
        leftPointer->next = tail;
        if(left==1){
            return r;
        }else{
            ListNode* headCopy = head;
            while(headCopy->next!=leftPointer){
                headCopy = headCopy->next;
            }
            headCopy->next = r;
        }
        return head;
    }
};