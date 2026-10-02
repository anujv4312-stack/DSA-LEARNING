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
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> mp;
        queue<pair<TreeNode*,int>> q;
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        
        q.push({root,0});
        
        while(q.empty()!=true){
            pair<TreeNode*,int> temp = q.front();
            q.pop();
            TreeNode* node = temp.first;
            int vr = temp.second;
            mp[vr] = node->val;
            
            if(node->left != nullptr){
                q.push({node->left,vr+1});
            }
            if(node->right != nullptr){
                q.push({node->right,vr+1});
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};