#include"TreeNode.h"
#include"queue"
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


class Solution {
public:
    // Node* connect(Node* root) {
    //     queue<Node *> q;
    //     if(root)
    //         q.push(root);
    //     while(!q.empty()){
    //         int n = q.size();
    //         for(int i = 0; i < n; i ++){
    //             Node * cur = q.front();
    //             q.pop();
    //             if(i == n-1)
    //                 cur->next = NULL;
    //             else 
    //                 cur->next = q.front();
    //             if(cur->left)
    //                 q.push(cur->left);
    //             if(cur->right)
    //                 q.push(cur->right);
    //         }
    //     }
    // }
    Node * connect(Node *root){
        connected(root);
        return root;
    }
    void connected(Node * root){
        if(root == NULL||root->left == NULL)
            return ;
        root->left->next = root->right;
        if(root->next)
            root->right->next = root->next->left;
            connected(root->left);
            connected(root->right);
    }
    
};
using namespace std;

int main(void){

}