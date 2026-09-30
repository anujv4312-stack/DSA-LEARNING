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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
     map<int,map<int,vector<int>>> nodes;
     queue<pair<TreeNode*,pair<int,int>>> q;
     vector<vector<int>> ans;
     if(root == nullptr){
        return ans;
     }   
     q.push(make_pair(root,make_pair(0,0)));
     while(q.empty()!=true){
        pair<TreeNode*,pair<int,int>> temp = q.front();
        q.pop();
        TreeNode* node = temp.first;
        int hr = temp.second.first;
        int vr = temp.second.second;
        nodes[vr][hr].push_back(node->val);
        if(node->left!=nullptr){
            q.push(make_pair(node->left,make_pair(hr+1,vr-1)));
        }
        if(node->right!=nullptr){
            q.push(make_pair(node->right,make_pair(hr+1,vr+1)));
        }
     }
     for(auto i : nodes){
        vector<int> temp;
        for(auto j : i.second){
            sort(j.second.begin(),j.second.end());
            for(auto k : j.second){
                temp.push_back(k);
            }
        }
        ans.push_back(temp);
     }
     return ans;
    }
};