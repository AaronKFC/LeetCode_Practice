/*
    Given binary tree, determine if height-balanced (all left & right subtrees height diff <= 1)

    Check if subtrees are balanced, if so, use their heights to determine further balance

    Time: O(n)
    Space: O(n)
*/

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

// Solution1 (My implementation)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        bool balance;
        dfs(root, balance);
        return balance;
        
    }
private:
    
    int dfs(TreeNode* root, bool& bal) {
        if (root == NULL) {
            // h = 0;
            bal = true;
            return 0;
        }
        
        int Lh = dfs(root->left, bal);
        bool Lbal = bal;
        int Rh = dfs(root->right, bal);
        bool Rbal = bal;
        bal = Lbal && Rbal && (abs(Lh-Rh) <= 1);
        
        return 1 + max(Lh, Rh);
    }
};


// solution2 (My implementation)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
private:
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int Lh = dfs(root->left);
        int Rh = dfs(root->right);
        if (Lh==-1 || Rh==-1 || abs(Lh-Rh) > 1) {
            return -1;
        }
        
        return 1 + max(Lh, Rh);
    }
};


// Solution (NeetCode)
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return dfs(root, height);
    }
private:
    bool dfs(TreeNode* root, int& height) {
        if (root == NULL) {
            height = -1;
            return true;
        }
        
        int left = 0;
        int right = 0;
        
        if (!dfs(root->left, left) || !dfs(root->right, right)) {
            return false;
        }
        if (abs(left - right) > 1) {
            return false;
        }
        
        height = 1 + max(left, right);
        return true;
    }
};