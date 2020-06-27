#include"iostream"
#include"queue"
#include "TreeNode.h"

using namespace std;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
    }
    string travLevel(TreeNode * root){
        string s;
        queue<TreeNode * > q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; ++i){
                TreeNode * cur = q.front();
                q.pop();
                if(cur){
                    s += to_string(cur->val)+',';
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else{
                    s += "*";
                }
            }
        }
        return s;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode * >q;
        auto trav = data.begin();

        TreeNode * root = new TreeNode(*trav-'0');
        q.push(root);

        while(!q.empty() && trav != data.end()){

            TreeNode * cur = q.front();
            q.pop();
            if(*(++trav) != '*'){
                TreeNode * p = new TreeNode(*trav - '0');
                cur->left = p;
                q.push(p);
            }
            else {
                cur->left = NULL;
            }
            if(*(++trav) != '*'){
                TreeNode * p = new TreeNode(*trav - '0');
                cur->right = p;
                q.push(p);
            }
            else {
                cur->right = NULL;
            }
        }
        return root;
    }

};


int main(){
    cout << "hello" << endl;

    Codec codec;

    TreeNode * root = CreateTree(0,9);
    string  s = codec.travLevel(root);
    for(auto i:s)
        cout << i;
    cout << endl;
    TreeNode * root1 = codec.deserialize(s);
    travLevel(root1);
    return 0;
}