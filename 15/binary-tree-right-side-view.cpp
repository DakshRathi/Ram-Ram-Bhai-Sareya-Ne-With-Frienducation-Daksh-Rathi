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
    void rightSideHelper(TreeNode* root, int level, vector<int>& ans)
    {
        if(!root) return;
        if(ans.size() == level) ans.push_back(root->val);

        rightSideHelper(root->right, level+1, ans);
        rightSideHelper(root->left, level+1, ans);
    }

    vector<int> rightSideView(TreeNode* root)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        vector<int> ans;
        rightSideHelper(root, 0, ans);
        return ans;
    }
};