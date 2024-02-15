#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        prev = next = NULL;
    }
};

Node* delLast(Node* head) {
    if (head == NULL)
        return NULL;
    if (head->next == NULL) {
        delete(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    delete(temp->next);
    return head;
}

Node* delHead(Node* head) {
    if (head == NULL )
        return NULL;
    if (head->next == NULL) {
        delete(head);
        return NULL;
    }
    Node* temp = head->next;
    temp->prev = NULL;
    delete(head);
    return temp;
}

Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;
    Node* temp = NULL;
    Node* curr = head;
    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(7);
    head->next->prev = head;
    head->next->next = new Node(10);
    head->next->next->prev = head->next;
    Node* temp = head;
    //Original DLL
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    Node* head1 = delLast(head);    //reverse(head);
    //cout << head1->data << "\n";
    //After reversing the DLL
    while (head1) {
        cout << head1->data << " ";
        head1 = head1->next;
    }
    return 0;
}