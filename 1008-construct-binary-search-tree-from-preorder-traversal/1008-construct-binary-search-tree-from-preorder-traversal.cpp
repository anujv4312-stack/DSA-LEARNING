/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int val) {
        TreeNode* cur = root;
        while(true){
            if(cur->val < val){
                if(cur->right == nullptr){
                     TreeNode* node = new TreeNode(val);
                   cur->right = node;
                   break; 
                }
                else{
                    cur = cur->right;
                }
            }
            else{
                if(cur->left == nullptr){
                   TreeNode* node = new TreeNode(val);
                   cur->left = node;
                   break;  
                }
                else {
                    cur = cur->left;
                }
            }
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1;i<preorder.size();i++){
            solve(root,preorder[i]);
        }
        return root;
    }
};