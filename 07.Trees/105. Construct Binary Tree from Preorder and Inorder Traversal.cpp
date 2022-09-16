/*
    Given 2 integer arrays preorder & inorder, construct & return the binary tree
    Ex. preorder = [3,9,20,15,7], inorder = [9,3,15,20,7] -> [3,9,20,null,null,15,7]

    Preorder dictates nodes, inorder dictates subtrees (preorder values, inorder positions)

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

// Solution1 (NeetCode)  faster.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int index = 0;
        return build(preorder, inorder, index, 0, inorder.size() - 1);
    }
private:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& index, int i, int j) {
        if (i > j) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[index]);
        
        int split = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (preorder[index] == inorder[i]) {
                split = i;
                break;
            }
        }
        index++;
        
        root->left = build(preorder, inorder, index, i, split - 1);
        root->right = build(preorder, inorder, index, split + 1, j);
        
        return root;
    }
};


// Solution2 (My implementation) assited by the vector slicing function
// faster but need more memory.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        int mid;
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i]==preorder[0]) {
                mid = i;
                break;
            }
        }
        
        vector<int> leftpreod, rightpreod, leftinod, rightinod;
        int lenP = preorder.size();
        int lenI = inorder.size();
        leftpreod = slice(preorder, 1, mid);
        leftinod = slice(inorder, 0, mid-1);
        rightpreod = slice(preorder, mid+1, lenP-1);
        rightinod = slice(inorder, mid+1, lenI-1);
        
        root->left = buildTree(leftpreod, leftinod);
        root->right = buildTree(rightpreod, rightinod);
        
        return root;
    }
private:
    vector<int> slice(vector<int>& arr, int X, int Y) {
        auto start = arr.begin() + X;
        auto end = arr.begin() + Y + 1;
        
        vector<int> result(Y+1-X);
        copy(start, end, result.begin());  //記得result要.begin()
        return result;
    }
};



// Solution3 (My implementation) similar to python method
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        int mid;
        for (int i=0; i<inorder.size(); i++) {
            if (inorder[i]==preorder[0]) {
                mid = i;
            }
        }
        
        vector<int> leftpreod, rightpreod, leftinod, rightinod;
        
        for(int i=1; i<mid+1; i++) {
            leftpreod.push_back(preorder[i]);
        }
        for(int i=0; i<mid; i++) {
            leftinod.push_back(inorder[i]);
        }
        for(int i=mid+1; i<preorder.size(); i++) {
            rightpreod.push_back(preorder[i]);
        }
        for(int i=mid+1; i<inorder.size(); i++) {
            rightinod.push_back(inorder[i]);
        }
        
        root->left = buildTree(leftpreod, leftinod);
        root->right = buildTree(rightpreod, rightinod);
        
        return root;
    }
};