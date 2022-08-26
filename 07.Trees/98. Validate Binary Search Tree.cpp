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
    bool isValidBST(TreeNode* root) {
        return isValid(root);
    }
private:
    struct TreeNode *Lmax;
    struct TreeNode *Lmin;
    struct TreeNode *Rmax;
    struct TreeNode *Rmin;
    struct TreeNode* max;
    struct TreeNode* min;
    
    bool isValid(TreeNode* root) {
        // if (root==NULL) {
        //     return true;
        // }
        if (root->left==NULL && root->right==NULL) {
            max = min = root;
            return true;
        } else if (root->left==NULL && root->val < root->right->val) {
            min = root;
            max = root->right;
            return true;
        } else if (root->right==NULL && root->val > root->left->val) {
            min = root->left;
            max = root;
            return true;
        } else if (root->left!=NULL && root->right!=NULL && root->val < root->right->val && root->val > root->left->val) {
            min = root->left;
            max = root->right;
            return true;
        } else {
            return false;
        }
        
        
        bool left = isValid(root->left, Lmax, Lmin);
        bool right = isValid(root->right, Rmax, Rmin);
        if (Lmax->val >= Rmin->val) {
            return false;
        } else {
            min = Lmin;
            max = Rmax;
        }
        // cout << "left=" << left << endl;
        // cout << "right=" << right << endl;
        return left && right;
    }
};