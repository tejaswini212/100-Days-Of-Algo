#include<bits/stdc++.h>
using namespace std;

int preIndex = 0;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

void printTree(Node* head) {
	if (head == NULL)
		return;
	printTree(head->left);
	
	printTree(head->right);
	cout << head->data << " ";
	
}

Node* cTree(int in[],int pre[],int is,int ie) {
	if (is > ie)
		return NULL;
	Node* root = new Node(pre[preIndex++]);
	int inIndex;
	for (int i = is; i <= ie; i++) {
		if (in[i] == root->data) {
			inIndex = i;
			break;
		}
	}
	root->left = cTree(in, pre, is, inIndex - 1);
	root->right = cTree(in, pre, inIndex + 1, ie);
	return root;
}

int main() {
	int pre[] = {20,10,40,30,50};
	int in[] = { 10,20,30,40,50};
	Node* head = cTree(in, pre, 0, 4);
	cout << "Inorder traversal for the constructed tree is: \n";
	printTree(head);
}