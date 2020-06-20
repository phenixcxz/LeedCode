#include"iostream"
#include"queue"
#include"vector"

using namespace std;

struct TreeNode{
public:
    int val ;
    TreeNode * left;
    TreeNode * right;
    TreeNode(int v = 0,TreeNode * l = NULL,TreeNode *r = NULL):val(v),left(l),right(r){}
};

class Solution{
public:
    TreeNode * midTree(vector<int> nums,int left,int right){
        if(left == right)
            return NULL;
        int middle = (left+right)>>1;
        TreeNode *root = new TreeNode(nums[middle]);
        root->left = midTree(nums,left,middle);
        root->right = midTree(nums,middle+1,right);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums){
        return midTree(nums,0,nums.size());
    }
};

class Solution1{
public:
    
};


int main(){
    int n = 0;
    vector<int> nums = {1,2,3,4,5};

    // TreeNode * root = CreateTree(nums.size()-1);

    return 0;
}
