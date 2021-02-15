#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void printCLL(Node* head) {
    if (head == NULL)
        return;
    Node* temp = head;
    /*cout << head->data << " ";
    for (temp = head->next; temp != head; temp = temp->next) {
        cout << temp->data << " ";
    }*/
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
}

Node* insertHCon(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == NULL)
        temp->next = temp;
    temp->next = head->next;
    head->next = temp;
    int t = head->data;
    head->data = temp->data;
    temp->data = t;
    return head;
}

Node* insertHead(Node* head, int x) {
    Node* temp = new Node(x);
    if (head == NULL)
        temp->next = temp;
    else {
        Node* curr = head;
        while (curr->next != head)
            curr = curr->next;
        curr->next = temp;
        temp->next = head;
    }
    return temp;
}

int main()
{
    Node* head = new Node(5);
    head->next = new Node(7);
    head->next->next = new Node(10);
    head->next->next->next = head;
    printCLL(head);
    cout << "\n";
    Node* temp = insertHCon(head, 15);
    printCLL(temp);
    return 0;
}