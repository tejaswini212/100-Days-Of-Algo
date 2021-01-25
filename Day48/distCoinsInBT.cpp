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
    int ans = 0;
    
    int countSteps(TreeNode* root){
        if(root==NULL)
            return 0;
        int leftSteps = countSteps(root->left);
        int rightSteps = countSteps(root->right);
        ans = ans+abs(leftSteps)+abs(rightSteps);
        return root->val+leftSteps+rightSteps-1;
    }
    
    int distributeCoins(TreeNode* root) {
        countSteps(root);
        return ans;
    }
};