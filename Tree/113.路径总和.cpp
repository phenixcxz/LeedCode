#include "TreeNode.h"
#include"stack"
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> nums;
        vector<int> num;
        if(root)
            dfs(nums,num,root,sum);
        return nums;
    }
    void dfs(vector<vector<int>>& nums,vector<int> &num,TreeNode * root, int sum){
        int resum = sum-root->val;
        num.push_back(root->val);
        if(resum == 0 && !root->left && !root->right)
            nums.push_back(num);
        if(root->left)
            dfs(nums,num,root->left,resum);
        if(root->right)
            dfs(nums,num,root->right,resum);
        num.pop_back();
    }
};

int main(void){
    TreeNode * root = CreateTree(1,9);
    Solution so;
    vector<vector<int>> nums = so.pathSum(root,5);
    for(auto i:nums){
        for(auto j:i){
            cout << j << "  ";
        }
        cout << endl;
    }
}