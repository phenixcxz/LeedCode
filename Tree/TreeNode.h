#ifndef TREENODE_H
#define TREENODE_H
#include"iostream"
#include"queue"
#include"stack"


using namespace std;
class TreeNode{
public:
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v =0,TreeNode * l = NULL,TreeNode * r = NULL):val(v),left(l),right(r){}
};

void travPre_R(TreeNode * root){
    if(!root)
        return ;
    cout << root->val << "  ";
    travPre_R(root->left);
    travPre_R(root->right);
}

void travIn_R(TreeNode * root){
    if(!root)
        return ;
    travIn_R(root->left);
    std::cout << root->val << "  ";
    travIn_R(root->right);
}

void travPost_R(TreeNode * root){
    if(!root)
        return ;
    travPost_R(root->left);
    travPost_R(root->right);
    std::cout << root->val << "  ";
}

void travPre_I(TreeNode * root){
    stack<TreeNode*> s;
    if(root)    
        s.push(root);
    while(!s.empty()){
        TreeNode * cur = s.top();
        s.pop();
        std::cout << cur->val << "  ";
        if(cur->right)
            s.push(cur->right);
        if(cur->left)
            s.push(cur->left);  
    }
}

void travIn_I(TreeNode * root){
    stack<TreeNode *> s;
    if(root)
        s.push(root);
    while(!s.empty()){
        while(s.top()->left){
            s.push(s.top()->left);
        }
        while(!s.empty()){
            TreeNode * cur = s.top();
            s.pop();
            cout << cur->val << "  ";
            if(cur->right){
                s.push(cur->right);
                break;
            }
        }
    }
}

void travPost_I(TreeNode * root){
    stack<TreeNode *> s;
    if(root)
        s.push(root);
    TreeNode * preNode = NULL;
    while(!s.empty()){
        while(s.top()->left)
            s.push(s.top()->left);
        while(!s.empty()){
            if(s.top()->right == NULL || s.top()->right == preNode){
                preNode = s.top();
                s.pop();
                cout << preNode->val << "  ";
            }
            else if(s.top()->right){
                s.push(s.top()->right);
                break;
            }
        }
    }
}

void travLevel(TreeNode * root){
    queue<TreeNode *>q;
    if(root)
        q.push(root);
    while(!q.empty()){
        TreeNode * cur = q.front();
        q.pop();
        cout << cur->val << "  ";
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
    }
    cout << endl;
}

TreeNode * CreateTree(int lo,int hi){
    if(lo > hi)
        return NULL;
    int middle = (hi+lo)/2;
    TreeNode * root = new TreeNode(middle);
    root->left = CreateTree(lo,middle-1);
    root->right = CreateTree(middle+1,hi);
    return root;
}


#endif