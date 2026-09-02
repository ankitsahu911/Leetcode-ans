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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return buildTrees(1, n);
    }

private:
    vector<TreeNode*> buildTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }

        vector<TreeNode*> allTrees;

        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftTrees = buildTrees(start, i - 1);
            vector<TreeNode*> rightTrees = buildTrees(i + 1, end);

            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root);
                }
            }
        }

        return allTrees;
    }
};