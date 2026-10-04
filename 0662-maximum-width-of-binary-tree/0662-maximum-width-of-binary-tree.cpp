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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        queue<pair<TreeNode*,long long>> q;
        int ans = 0;
        q.push({root,0});
        while(q.empty()!= true){
            long long min = q.front().second;
            int size = q.size();
            long long first,second;
            for(int i = 0;i<size ; i++){
                long long cur_ind = q.front().second-min;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = cur_ind;
                if(i==size-1) second = cur_ind;
                if(node->left != nullptr){
                    q.push({node->left,cur_ind*2+1});
                }
                if(node->right != nullptr){
                    q.push({node->right,cur_ind*2+2});
                }
            }
            ans = max(ans,(int)((second-first)+1));
        }
        return ans;
    }
};