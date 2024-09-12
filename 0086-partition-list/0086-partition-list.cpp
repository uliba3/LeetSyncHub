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
    ListNode* partition(ListNode* head, int x) {
        if(head == nullptr){
            return head;
        }
        ListNode* l = new ListNode(x-1);
        ListNode* start = l;
        l->next = head;
        ListNode* r = head;
        while(r->val<x){
            r = r->next;
            if(r == nullptr){
                return head;
            }
        }
        while(l->next!=nullptr&&l->next->val < x){
            l = l->next;
        }
        if(l->next==nullptr){
            return head;
        }
        while(r->next!=nullptr){
            ListNode* p = r->next;
            if(p->val < x){
                r->next = p->next;
                p->next = l->next;
                l->next = p;
                l = l->next;
            }else{
                r = r->next;
            }
        }
        return start->next;;
    }
};