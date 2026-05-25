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
    unordered_map<int, int> inorderMap; 
    int preIndex = 0; 

    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int left, int right) {
        if (left > right) return NULL; 

        int rootValue = preorder[preIndex++]; 
        TreeNode* root = new TreeNode(rootValue);

        int inorderIndex = inorderMap[rootValue]; 
        root->left = buildTreeHelper(preorder, inorder, left, inorderIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inorderIndex + 1, right);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]]=i;
        }
        return buildTreeHelper(preorder, inorder, 0,  inorder.size() - 1 );
    }
};
