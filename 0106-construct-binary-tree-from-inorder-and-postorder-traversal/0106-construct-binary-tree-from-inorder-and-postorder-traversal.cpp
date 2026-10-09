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
    TreeNode* maketree(vector<int>& postorder,int postart,int poend,vector<int>& inorder,int instart,int inend,map<int,int> &mpp){
        if(postart>poend || instart>inend){
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[poend]);
        int inroot = mpp[root->val];
        int numsleft = inroot-instart;

        root->left = maketree(postorder,postart,postart+numsleft-1,inorder,instart,inroot-1,mpp);
        root->right = maketree(postorder,postart+numsleft,poend-1,inorder,inroot+1,inend,mpp);

        return root;
    } 
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mpp;
        for(int i =0;i<inorder.size();i++){
            mpp[inorder[i]] = i;
        }
        TreeNode* root = maketree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
        return root;
    }
};