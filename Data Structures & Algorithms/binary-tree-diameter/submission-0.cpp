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
    int h = 0;
    int heightOfTree(TreeNode* root){

    if(root == NULL)
        return 0;

    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);

    return max(lh, rh) + 1;
}
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        return 0;

        int lh = heightOfTree(root->left);
        int rh = heightOfTree(root->right);

        h = max(lh + rh, h);
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        
        return h;
    }
};