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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr){
            return head;
        }
        ListNode* tail = head;
        int count = 1;
        while(tail->next!=nullptr){
            tail = tail->next;
            count++;
        }
        tail->next = head;
        k = k%count;
        cout << k << endl;
        for(int i = 0; i < count-k; i++){
            tail=tail->next;
            head=head->next;
            cout << tail->val << endl;
        }
        tail->next = nullptr;
        return head;
    }
};