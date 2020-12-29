#include<bits/stdc++.h>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

void printBST(Node* head) {
	if (head == NULL)
		return;
	cout << head->data << " ";
	printBST(head->left);
	
	printBST(head->right);
	
}
	
Node* constructBST(int arr[], int start, int end) {
	if (start > end)
		return NULL;
	
	int mid = (start + end) / 2;
	Node* root = new Node(arr[mid]);
	root->left = constructBST(arr, start, mid - 1);
	root->right = constructBST(arr, mid + 1, end);

	return root;
}

int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10};
	Node *head = constructBST(arr, 0, 9);
	printBST(head);
	return 0;
}