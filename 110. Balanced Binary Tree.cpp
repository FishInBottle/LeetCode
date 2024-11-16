/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int chkSub(TreeNode* root, bool* isBalanced) {
        /*
        Skip the remained uncheck nodes.
        Because if a child node is not a balanced tree, then the entire tree is
        not a balanced tree.
         */
        if (false == *isBalanced)
            return 0;

        if (nullptr != root && nullptr == root->left &&
            nullptr == root->right) {
            return 1;
        } else if (nullptr == root) {
            return 0;
        } else {
            int left = 0;
            int right = 0;

            if (nullptr != root->left)
                left = chkSub(root->left, isBalanced);

            if (nullptr != root->right)
                right = chkSub(root->right, isBalanced);

            /* Marked as non-balanced once a unbalanced sub-tree is found */
            if (1 < (left - right) || -1 > (left - right))
                *isBalanced = false;

            if (left >= right)
                return left + 1;
            else
                return right + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;

        chkSub(root, &isBalanced);

        return isBalanced;
    }
};