#include <bits/stdc++.h>

using std::max;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    int maxLen = 0;
    int getLength(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left = getLength(root->left);
        int right = getLength(root->right);

        if (root->left != nullptr && root->val != root->left->val)
        {
            left = 0;
        }
        if (root->right != nullptr && root->val != root->right->val)
        {
            right = 0;
        }
        this->maxLen = max(this->maxLen, left + right);

        return max(right, left) + 1;
    }

public:
    int longestUnivaluePath(TreeNode *root)
    {
        getLength(root);

        return this->maxLen;
    }
};
