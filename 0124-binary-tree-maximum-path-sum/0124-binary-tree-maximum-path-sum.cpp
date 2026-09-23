class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        dfs(root, maxSum);
        return maxSum;
    }

private:
    int dfs(TreeNode* node, int& maxSum) {
        if (!node) return 0;

        int leftGain = std::max(0, dfs(node->left, maxSum));
        int rightGain = std::max(0, dfs(node->right, maxSum));

        maxSum = std::max(maxSum, node->val + leftGain + rightGain);

        return node->val + std::max(leftGain, rightGain);
    }
};