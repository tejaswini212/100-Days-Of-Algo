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
    int nCamera;
    int minCameraCover(TreeNode* root) {
        nCamera = 0;
        pair<bool,bool> temp = cnt_cameras(root);
        if(!temp.second)
            nCamera++;
        return nCamera;
    }
    
    pair<bool,bool> cnt_cameras(TreeNode* root){
        if(root==NULL)
            return {false,true};
        pair<bool,bool> L=cnt_cameras(root->left);
        pair<bool,bool> R=cnt_cameras(root->right);
        bool has_cam=false;
        bool is_monitored=false;
        if(L.first || R.first)
            is_monitored=true;
        if(!L.second || !R.second){
            has_cam=true;
            is_monitored=true;
            nCamera++;
        }
        return {has_cam,is_monitored};
    }
};