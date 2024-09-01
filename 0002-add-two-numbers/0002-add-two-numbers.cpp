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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* node;
        if(l1==nullptr&&l2==nullptr){
            return nullptr;
        }
        if(l1==nullptr){
            l1 = new ListNode(0);
        }
        if(l2==nullptr){
            l2 = new ListNode(0);
        }
        node = new ListNode((l1->val+l2->val)%10);
        int nextVal = (l1->val+l2->val - (l1->val+l2->val)%10)/10;
        if(nextVal > 0){
            if(l1->next==nullptr){
                l1->next = new ListNode(nextVal);
            }else{
                l1->next->val += nextVal;
            }
        }
        node->next = addTwoNumbers(l1->next, l2->next);
        return node;
    }
};