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
    int ans = INT_MIN;
    int traverse(TreeNode* root)
    {
        if(!root) return 0;
        // if(root->left==nullptr and root->right==nullptr)
        // {
        //     return root->val;
        // }
        int lefts = max(0,traverse(root->left));
        int rights= max(0,traverse(root->right));
        int sum = lefts+rights+root->val;
        
        ans = max(ans,sum);
        
        return max(lefts,rights)+root->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        traverse(root);
        return ans;
    }
};