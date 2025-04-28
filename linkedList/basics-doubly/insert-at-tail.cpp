#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
    };

    Node(int data1)
    {
        data = data1;
        next = NULL;
        back = NULL;
    };
};

void printDL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
}

Node *insertAtTail(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
        return newNode;

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = newNode;
    newNode->back = tail;

    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = insertAtTail(head, 5);

    printDL(head);
}