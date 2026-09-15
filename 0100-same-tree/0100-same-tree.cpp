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
    void solve(TreeNode* p, vector<int> &arr){
        if(p == nullptr){
            arr.push_back(999);
            return;
        }
        arr.push_back(p->val);
        solve(p->left,arr);
        solve(p->right,arr);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> arr;
        vector<int> arr2;
        solve(p,arr);
        solve(q,arr2);
        if(arr.size()!=arr2.size()) return false;
        for(int i = 0;i<arr.size();i++){
            if(arr[i]!=arr2[i]){
                return false;
            }
        }
        return true;
    }
};