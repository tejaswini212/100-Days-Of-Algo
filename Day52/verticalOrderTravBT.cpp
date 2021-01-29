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
    map<int, vector<pair<int,int>>> mp;
    
    void traverseUtil(TreeNode* root,int x,int y){
        if(root==NULL)
            return;
        mp[x].push_back({y,root->val});
        traverseUtil(root->left,x-1,y+1);
        traverseUtil(root->right,x+1,y+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        mp.clear();
        vector<int> temp;
        traverseUtil(root,0,0);
        vector<vector<int>> ans;
        for(auto it:mp){
            temp.clear();
            sort(it.second.begin(),it.second.end());
            for(auto itr:it.second)
                temp.push_back(itr.second);
            ans.push_back(temp);
        }
        return ans;
    }
};