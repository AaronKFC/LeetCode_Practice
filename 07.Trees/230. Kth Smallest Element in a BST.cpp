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

// Solution1 (My implementation)  similar to python solution
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        int n = 0;
        TreeNode* cur = root;
        
        while (cur!=NULL || !stk.empty()) {
            while (cur!=NULL) {
                stk.push(cur);
                cur = cur->left;
            }
            
            cur = stk.top();
            stk.pop();
            n++;
            if (n==k) {
                return cur->val;
            }
            cur = cur->right;
        }
        return 0;
    }
};



// Solution2 (NeetCode)
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0;
        inorder(root, k, result);
        return result;
    }
private:
    void inorder(TreeNode* root, int& k, int& result) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, k, result);
        k--;
        if (k == 0) {
            result = root->val;
            return;
        }
        inorder(root->right, k, result);
    }
};