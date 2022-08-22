#include <bits/stdc++.h>

using std::vector;
using std::string;
using std::to_string;
using std::max;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    vector<vector<string>> table;
    int maxLevel(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(this->maxLevel(root->left), this->maxLevel(root->right)) + 1;
    }
    void fill(TreeNode *root, int level, int index, int space) {
        if (root == nullptr) return;
        this->table[level][index] = to_string(root->val);
        fill(root->left, level + 1, index - space, space / 2);
        fill(root->right, level + 1, index + space, space / 2);
    }
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int level = this->maxLevel(root);
        this->table.resize(level, vector<string>(pow(2, level) - 1, ""));
        fill(root, 0, pow(2, level - 1) - 1, pow(2, level - 2));

        return this->table;
    }
};
