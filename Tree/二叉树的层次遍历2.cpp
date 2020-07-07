#include "TreeNode.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> nums;

        stack<vector<int>> s;
        queue<TreeNode *> q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            for(int i = 0; i < n; i ++){
                TreeNode * cur = q.front();
                q.pop();
                temp.push_back(cur->val);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);         
            }
            s.push(temp);
        }

        while(!s.empty()){
            nums.push_back(s.top());
            s.pop();
        }
        return nums;
    }
};

int main(void){
    Solution solution;
    TreeNode * root = CreateTree(1,9);

    travLevel(root);
    vector<vector<int>> nums = solution.levelOrderBottom(root);
    for(auto i:nums){
        for(auto j:i)
            cout << j << "  ";
        cout << endl;
    }
    return 0;

}