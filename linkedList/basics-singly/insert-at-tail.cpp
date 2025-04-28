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

Node *insertAtTail(Node *head, int val)
{
    Node *newNode = new Node(val);

    if (!head)
        return newNode;

    Node *curr = head;
    while (curr->next)
    {
        curr = curr->next;
    }

    curr->next = newNode;
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = insertAtTail(head, 5);

    printLL(head);
}