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
    //map<int,int> mp;
    int sum=0;
    int maxLev=0;
    void leavesSumUtil(TreeNode* root,int lvl){
        if(root==NULL) return;
        if(lvl>maxLev) sum=0, maxLev=lvl;
        if(lvl==maxLev) sum+=root->val;
        leavesSumUtil(root->left,lvl+1);
        leavesSumUtil(root->right,lvl+1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        leavesSumUtil(root,0);        
        return sum;
    }
};