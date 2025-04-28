#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    };

    Node(int data1)
    {
        data = data1;
        next = NULL;
    };
};

void printLL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    };
};

Node* deleteLastNode(Node* head){
    if(!head || !head->next) return NULL;

    Node* temp = head;
    while(temp->next->next!=NULL) temp = temp->next;

    delete temp->next;
    temp->next = NULL;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = deleteLastNode(head);

    printLL(head);
}