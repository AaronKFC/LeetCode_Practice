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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // if (subRoot==NULL) {return true;}   //似乎可有可無？
        if (root==NULL) {
            return false;
        }
        if (sameTree(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
private:
    bool sameTree(TreeNode* root, TreeNode* subRoot) {
        if (root==NULL && subRoot==NULL) {
            return true;
        }
        if (root!=NULL && subRoot!=NULL && root->val==subRoot->val) {
            // return sameTree(root->left, subRoot) && sameTree(root->right, subRoot);
            return sameTree(root->left, subRoot->left) && sameTree(root->right, subRoot->right);
        }
        return false;
    }
};