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
    void solve(TreeNode * node, int maxVal, int &ans)
    {
        if(!node) return;
        if(node->val >= maxVal)
        {
            ans++;
            maxVal = node->val;
        }
        solve(node->left, maxVal, ans);
        solve(node->right, maxVal, ans);
    }

    int goodNodes(TreeNode* root)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int maxVal = root->val;
        int ans = 0;
        solve(root, maxVal, ans);
        return ans;
    }
};