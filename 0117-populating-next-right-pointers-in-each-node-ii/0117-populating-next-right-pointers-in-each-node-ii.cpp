/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<pair<Node*, int>> que;
        que.push(make_pair(root, 0));
        int height = 0;
        while(!que.empty()){
            Node* currentNode = que.front().first;
            int currentH = que.front().second;
            Node* firstNode = currentNode;
            que.pop();
            cout << currentNode->val << endl;
            if(currentNode->left){
                que.push(make_pair(currentNode->left, height+1));
            }
            if(currentNode->right){
                que.push(make_pair(currentNode->right, height+1));
            }
            while(!que.empty()&&que.front().second == height){
                Node* node = que.front().first;
                int h = que.front().second;
                cout << node->val << endl;
                que.pop();
                currentNode->next = node;
                currentNode = node;
                if(currentNode->left){
                    que.push(make_pair(currentNode->left, height+1));
                }
                if(currentNode->right){
                    que.push(make_pair(currentNode->right, height+1));
                }
            }
            height++;
        }
        return root;
    }
};