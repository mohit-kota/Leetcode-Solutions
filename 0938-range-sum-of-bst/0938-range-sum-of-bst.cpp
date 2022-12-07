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
    // void traversal(TreeNode* root,int low, int high,int &sum)
    // {
    //     if(root==NULL) return ;
    //     if(root->val>=low && root->val<=high)
    //     {
    //         sum+=root->val;
    //     }
    //     traversal(root->left,low,high,sum);
    //     traversal(root->right,low,high,sum);
    // }
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(root==NULL) return 0;
        //int sum=0;
        //traversal(root,low,high,sum);
        return  ((root->val>=low && root->val<=high)?root->val:0) + rangeSumBST(root->left,low,high)+rangeSumBST(root->right,low,high) ;
        
    }
};