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
    int countNodes(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = getleftheight(root);
        int rightHeight = getrightheight(root);
        if (leftHeight == rightHeight) return (1 << leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
private:
    int getleftheight(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->left;
        }
        return h;
    }
    int getrightheight(TreeNode* root) {
        int h = 0;
        while (root) {
            h++;
            root = root->right;
        }
        return h;
    }
};