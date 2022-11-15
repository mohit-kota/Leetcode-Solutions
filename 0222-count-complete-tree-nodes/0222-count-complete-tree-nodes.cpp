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
    int count=0;
    void len(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        count++;
        len(root->left);
        len(root->right);
    }
    int countNodes(TreeNode* root) 
    {
        len(root);
        return count;
    }
};