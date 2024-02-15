class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        containsOne(root);
        return root;
    }
    void containsOne(TreeNode* &node){
        if(!node)
            return;
        containsOne(node->left);
        containsOne(node->right);
        if(!node->left && !node->right && !node->val)
            node=NULL;
        return;
    }
    
};