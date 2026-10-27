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
    TreeNode* prev;
    TreeNode* first;
    TreeNode* adj;
    TreeNode* last;
    void solve(TreeNode* root){
        if(root == nullptr){
            return;
        }
        solve(root->left);
        if(prev!= nullptr && (prev->val > root->val)){
            if(first == nullptr){
                first = prev;
                adj = root;
            }
            else{
                last = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = adj = last = nullptr;
        prev = new TreeNode(INT_MIN);
        solve(root);
        if(first != nullptr && last != nullptr){
            swap(first->val,last->val);
        }
        else if (first != nullptr && adj != nullptr){
            swap(first->val,adj->val);
        }
    }
};