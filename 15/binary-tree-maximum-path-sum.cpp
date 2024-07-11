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
private:
    int maxSum = INT_MIN;
public:
    int Helper(TreeNode* root)
    {
		// base case
        if (!root) return 0; 
		
		// recursing through left and right subtree
        int lMax = Helper(root->left);
        int rMax = Helper(root->right);

		// finding all the four paths and the maximum between all of them
        int maxrl = max(lMax, rMax);
        int maxOneNodeRoot = max(root->val, (root->val + maxrl));
        int maxAll = max(maxOneNodeRoot, lMax + rMax + root->val);
		
		// Storing the result in the maxSum holder
        maxSum = max(maxSum, maxAll);
		
		// returning the value if root was part of the answer
        return maxOneNodeRoot;

    }

    int maxPathSum(TreeNode* root)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        Helper(root);
        return maxSum;
    }
};