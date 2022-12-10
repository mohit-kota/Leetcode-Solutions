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
    long long total = 0 , maxi = 0;
    void takesum(TreeNode* root)
    {
        if(!root)
        {
            return ;
        }
        total+=root->val;
        takesum(root->left);
        takesum(root->right);
        
    }
    int mod = 1e9+7;
    int recur(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int left = recur(root->left);
        int right = recur(root->right);
        maxi = max(maxi,max((total-right)*right,(total-left)*left));
        int sum = root->val + left + right;
        return sum;
    }
    int maxProduct(TreeNode* root) 
    {

        takesum(root);
        recur(root);
        return maxi%mod;
    }
};