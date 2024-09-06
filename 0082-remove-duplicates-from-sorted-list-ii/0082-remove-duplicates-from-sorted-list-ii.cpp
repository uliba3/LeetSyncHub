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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyHead = new ListNode(-101);
        dummyHead->next = nullptr;
        ListNode* l = dummyHead;
        ListNode* m = head;
        ListNode* r = nullptr;
        ListNode* p = dummyHead;
        if(m!=nullptr){
            r = m->next;
        }
        while(m!=nullptr){
            if(r==nullptr){
                if(l->val!=m->val){
                    p->next = m;
                    p = p->next;
                }
            }else{
                if(l->val!=m->val&&m->val!=r->val){
                    p->next = m;
                    p = p->next;
                }
            }
            l = m;
            m = m->next;
            if(r!=nullptr){
                r=r->next;
            }
        }
        p->next = nullptr;
        return dummyHead->next;
    }
};