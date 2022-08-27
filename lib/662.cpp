#include <bits/stdc++.h>

using std::queue;

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
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long int maxLength = 0;
        queue<TreeNode*> lst({root});
        auto push = [& lst](TreeNode* root) {
            if (root->left != nullptr) {
                root->left->val = (unsigned long long int)root->val << 1;
                lst.push(root->left);
            }
            if (root->right != nullptr) {
                root->right->val = ((unsigned long long int)root->val << 1) + 1;
                lst.push(root->right);
            }
        };

        root->val = 0;
        do{
            if ((unsigned long long int)lst.back()->val - (unsigned long long int)lst.front()->val > maxLength) maxLength = (unsigned long long int)lst.back()->val - (unsigned long long int)lst.front()->val;
            int size = lst.size();
            for (int i = 0; i < size; ++i) {
                push(lst.front());
                lst.pop();
            }
        }while(!lst.empty());

        return ++maxLength;
    }
};
