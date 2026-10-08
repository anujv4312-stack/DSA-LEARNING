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
    TreeNode* maketree(vector<int>& preorder,int prestart, int prend,vector<int>& inorder,int instart,int inend,map<int,int>& mpp){
        if(prestart>prend || instart>inend) return nullptr;

        TreeNode* node = new TreeNode(preorder[prestart]);
        int inroot = mpp[node->val];
        int numsleft = inroot - instart;

        node->left = maketree(preorder, prestart+1,prestart+numsleft,inorder,instart,inroot-1,mpp);
        node->right = maketree(preorder,prestart+numsleft+1,prend,inorder,inroot+1,inend,mpp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       map<int,int> mpp;
       for(int i =0;i<=inorder.size()-1 ; i++){
        mpp[inorder[i]] = i;
       } 
       TreeNode *root = maketree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mpp);
       return root;
    }
};