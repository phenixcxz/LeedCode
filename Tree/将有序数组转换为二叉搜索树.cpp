#include"TreeNode.h"

using namespace std;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = createTree(nums,0,nums.size()-1);
        return root;
    }
    TreeNode * createTree(vector<int> & nums,int lo,int hi){
        if(lo > hi)
            return NULL;
        int temp =(lo+hi)/2;
        TreeNode * root = new TreeNode(nums[temp]);
        root->left = createTree(nums,lo,temp-1);
        root->right = createTree(nums,temp+1,hi);
        return root;
    }
};

int main(void){
    Solution solution;
    vector<int> nums = {-10,-3,0,5,9};
    TreeNode * root = solution.sortedArrayToBST(nums);
    travLevel(root);
    return 0;
}