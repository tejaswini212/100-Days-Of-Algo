class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            long long int sum=0, count=0;
            queue<TreeNode*> temp;
            while(!q.empty()){
                TreeNode* n=q.front();
                q.pop();
                sum += n->val;
                count++;
                if(n->left!=NULL)
                    temp.push(n->left);
                if(n->right!=NULL)
                    temp.push(n->right);
            }
            q = temp;
            res.emplace_back(sum*1.0/count);
        }
        return res;
    }
};