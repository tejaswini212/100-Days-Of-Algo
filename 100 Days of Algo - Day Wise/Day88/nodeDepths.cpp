#include<iostream>
#include<vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

vector<int> d;

int traverse(BinaryTree *root,int depth){
	if(root==NULL)
		return 0;
	d.emplace_back(depth);
	traverse(root->left,depth+1);
	traverse(root->right,depth+1);
	return 0;
}

int nodeDepths(BinaryTree *root) {
	int num=traverse(root,0);
	int res=0;
	for(int i=0;i<d.size();i++)
		res+=d[i];
	d.clear();
	return res;
}
