#include"iostream"

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int a = 0,TreeNode* l = nullptr,TreeNode* r = nullptr):val(a),left(l),right(r){}

};

class Solution{
public:
    int *last = NULL;
    bool isValidBST(TreeNode* root){
        if(root){
            if(!isValidBST(root->left))
                return false;
            if(last && *last>= root->val)
                return false;
            last = &root->val;
            if(!isValidBST(root->right))
                return false;
            return true;
        }
        return true;
    }
    
};

int main(){
    cout << "hello" << endl;
    return 0;
}