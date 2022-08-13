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
    bool isBalanced(TreeNode* root) {
        
        dfs(root, balance);
        return balance;
        
    }
private:
    // int h, Lh, Rh;
    // bool balance, Lbal, Rbal;
    bool balance;
    
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


// Anothoer solution
// class Solution {
// public:
//     bool isBalanced(TreeNode* root) {
        
        
//         return dfs(root) != -1;
        
//     }
// private:
//     // int h, Lh, Rh;
    
    
//     int dfs(TreeNode* root) {
//         if (root == NULL) {
//             return 0;
//         }
        
//         int Lh = dfs(root->left);
//         int Rh = dfs(root->right);
//         if (Lh==-1 || Rh==-1 || abs(Lh-Rh) > 1) {
//             return -1;
//         }
        
//         return 1 + max(Lh, Rh);
//     }
// };

