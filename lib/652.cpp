#include <bits/stdc++.h>

using std::string;
using std::to_string;
using std::unordered_map;
using std::vector;

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
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        vector<TreeNode *> result;
        unordered_map<string, int> mp;
        helper(root, result, mp);
        return result;
    }
    string helper(TreeNode *root, vector<TreeNode *> &result,
                  unordered_map<string, int> &mp)
    {
        string str;
        if (!root)
            return "#";
        str = to_string(root->val) + ' ' + helper(root->left, result, mp) + ' ' + helper(root->right, result, mp);
        if (mp[str] == 1)
            result.push_back(root);
        mp[str]++;
        return str;
    }
};
