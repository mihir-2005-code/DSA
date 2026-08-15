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
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxDepth(root, maxi);
        return maxi;
    }
    int maxDepth(TreeNode* node, int& maxi) {
        if (node == NULL) {
            return 0;
        }
        int lsum = max(0,maxDepth(node->left,maxi));
        int rsum = max(0,maxDepth(node->right,maxi));
        maxi = max(maxi,lsum+rsum+(node->val));
        return node->val + max(lsum,rsum);
    }
};