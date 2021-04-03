class Solution {
public:
    bool equals(TreeNode* s,TreeNode* t){
        if(s==NULL && t==NULL)
            return true;
        if(s==NULL || t==NULL)
            return false;
        return s->val==t->val && equals(s->left,t->left) && equals(s->right,t->right);
    }
    
    bool traverse(TreeNode* s,TreeNode* t){
        return s && (equals(s,t) || traverse(s->left,t) || traverse(s->right,t));
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
       return traverse(s,t);
    }
};