#include <bits/stdc++.h>

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
    int low;
    int high;
    void trim(TreeNode *&root)
    {
    cut:
        if (root == nullptr)
            return;
        if (root->val > this->high)
        {
            root = root->left;
            goto cut;
        }
        if (root->val < this->low)
        {
            root = root->right;
            goto cut;
        }
        this->trim(root->left);
        this->trim(root->right);
    }

public:
    TreeNode *trimBST(TreeNode *root, int low, int high)
    {
        this->low = low;
        this->high = high;
        trim(root);

        return root;
    }
};
