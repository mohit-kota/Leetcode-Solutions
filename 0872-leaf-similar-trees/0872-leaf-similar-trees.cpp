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
    void getleafs(TreeNode* root,vector<int>&vec)
    {
        if(root==nullptr) return ;
        if(root->left==nullptr and root->right==nullptr)
        {
            vec.push_back(root->val);
            return;
        }
        
        getleafs(root->left,vec);
        getleafs(root->right,vec);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int>vec1;
        getleafs(root1,vec1);
        vector<int>vec2;
        getleafs(root2,vec2);
        return vec1==vec2;
    }
};