#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node* random;
	Node(int x) {
		data = x;
		next = random = NULL;
	}
};

void print(Node* start) {
	Node* ptr = start;
	while (ptr) {
		cout << "Data at current: " << ptr->data << " Data at random: " << ptr->random->data << "\n";
		ptr = ptr->next;
	}
}

Node* clone(Node* start) {
	Node* curr = start;
	Node* temp;
	while (curr) {
		temp = curr->next;
		curr->next = new Node(curr->data);
		curr->next->next = temp;
		curr = temp;
	}
	curr = start;
	while (curr) {
		if (curr->next)
			curr->next->random = (curr->random) ? curr->random->next : curr->random;
		curr = (curr->next) ? curr->next->next : curr->next;
	}
	Node* original = start;
	Node* copy = start->next;
	temp = copy;
	while (original && copy) {
		original->next = (original->next) ? original->next->next : original->next;
		copy->next = (copy->next)?copy->next->next : copy->next;

		original = original->next;
		copy = copy->next;
	}
	return temp;
}

int main() {
	Node* start=new Node(1);
	start->next = new Node(2);
	start->next->next = new Node(3);
	start->next->next->next = new Node(4);
	start->next->next->next->next = new Node(5);
	//Random pointers
	//1->3
	start->random = start->next->next;
	//2->1
	start->next->random = start;
	//3->5,4->5
	start->next->next->random = start->next->next->next->next;
	start->next->next->next->random= start->next->next->next->next;
	//5->2
	start->next->next->next->next->random = start->next; 

	cout << "Original list:\n";
	print(start);

	Node* copied_list = clone(start);

	cout << "Copied list:\n";
	print(copied_list);
	return 0;
}
