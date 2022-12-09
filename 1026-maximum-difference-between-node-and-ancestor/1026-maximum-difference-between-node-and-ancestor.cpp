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
    int recur(TreeNode* root,int maxi,int mini)
    {
        if(root==nullptr)
        {
            return abs(maxi-mini);
        }
        
        maxi = max(maxi,root->val);
        mini = min(mini,root->val);
        int left = recur(root->left,maxi,mini);
        int righ = recur(root->right,maxi,mini);
        
        return max(left,righ);
    }
    int maxAncestorDiff(TreeNode* root) 
    {
        int maxi = -1;
        int mini = INT_MAX;
        return recur(root,maxi,mini);        
    }
};