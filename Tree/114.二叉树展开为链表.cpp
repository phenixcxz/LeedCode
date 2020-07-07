#include"TreeNode.h"

using namespace std;

class Solution {
public:
    // void flatten(TreeNode* root) {
    //     vector<TreeNode *> temp;
    //     travPre(root,temp);
    //     for(int i = temp.size()-1; i > 0; i--){
    //         temp[i-1]->right = temp[i];
    //         temp[i-1]->left = NULL;
    //     }
    // }
    // void travPre(TreeNode *root ,vector<TreeNode *> &temp){
    //     if(!root)
    //         return ;
    //     temp.push_back(root);
    //     travPre(root->left,temp);
    //     travPre(root->right,temp); 
    // }
    TreeNode * last = NULL;
    void flatten(TreeNode * root){
        if(root == NULL)
            return ;
        flatten(root->right);
        flatten(root->left);
        root->right = last;
        root->left = NULL;
        last = root;
    }
};
int main(){
    Solution sn;

    TreeNode *root = CreateTree(1,9);
    travPre_R(root);
    cout << endl;
    sn.flatten(root);

     travPre_R(root);
    return 0;

}