#include "TreeNode.h"

using namespace std;

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        return (left && right)? 1+min(left,right):1+left+right;
    }
};


int main(void){
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);

    Solution so;

    cout << so.minDepth(root) << endl;
    return 0;
}