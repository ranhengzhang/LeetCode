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
public:
    int sum = 0;
    int maxLevel = 0;
    void entry(TreeNode *root, int level)
    {
        if (root == nullptr)
        {
            if (level > this->maxLevel + 1)
            {
                this->maxLevel = level - 1;
                this->sum = 0;
            }

            return;
        }
        this->entry(root->left, level + 1);
        this->entry(root->right, level + 1);
        if (level == this->maxLevel)
        {
            this->sum += root->val;
        }
    }
    int deepestLeavesSum(TreeNode *root)
    {
        this->entry(root, 0);

        return this->sum;
    }
};
