class Solution {
public:
    TreeNode* build(vector<int>& preorder, int& preIdx, int inStart, int inEnd, unordered_map<int, int>& inMap) {
        // Base case: if there are no elements to process
        if (inStart > inEnd) return nullptr;

        // 1. Pick the current root from Preorder
        int currRootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(currRootVal);

        // 2. Find the index of this root in Inorder
        int inIdx = inMap[currRootVal];

        // 3. Recursively build the subtrees
        // IMPORTANT: Must build LEFT before RIGHT because that's the Preorder sequence
        root->left = build(preorder, preIdx, inStart, inIdx - 1, inMap);
        root->right = build(preorder, preIdx, inIdx + 1, inEnd, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        int preIdx = 0;
        return build(preorder, preIdx, 0, inorder.size() - 1, inMap);
    }
};