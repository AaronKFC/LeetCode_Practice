/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//Solution 1
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val < root->val && q->val < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (p->val > root->val && q->val > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        } else {
            return root;
        }
    }
};

//Solution 2
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* curr=root;
        while (curr!=NULL) {
            if (p->val < curr->val && q->val < curr->val) {
                curr = curr->left;
            } else if (p->val > curr->val && q->val > curr->val) {
                curr = curr->right;
            } else {
                return curr;
            }
        }
        return curr;
        // return NULL; //NeetCode的寫法
    }
};