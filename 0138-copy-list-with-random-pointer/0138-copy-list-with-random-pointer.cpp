/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:

public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr){
            return nullptr;
        }
        Node* copyNode = new Node(head->val);
        Node* copyNodeHead = copyNode;
        Node* pointer = head;
        while(pointer->next!=nullptr){
            pointer = pointer->next;
            copyNode->next = new Node(pointer->val);
            copyNode = copyNode->next;
        }
        pointer = head;
        Node* pointer1 = pointer;
        Node* copyPointer = copyNodeHead;
        Node* copyPointer1 = copyNodeHead;
        while(pointer!=nullptr){
            if(pointer->random==nullptr){
                copyPointer->random = nullptr;
            }else{
                pointer1 = head;
                copyPointer1 = copyNodeHead;
                while(pointer1!=nullptr){
                    if(pointer->random==pointer1){
                        copyPointer->random = copyPointer1;
                        break;
                    }else{
                        pointer1 = pointer1->next;
                        copyPointer1 = copyPointer1->next;
                    }
                }
            }
            pointer = pointer->next;
            copyPointer = copyPointer->next;
        }
        return copyNodeHead;
    }
};