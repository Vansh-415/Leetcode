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
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        check(root);
        return result;
    }
private:
    int k;
    int result;
    void check(TreeNode* node){
        if (node != nullptr) {
            check(node->left);
            if (--k == 0) {
                result = node->val;
                return;
            }
            check(node->right);
        }
    }
};