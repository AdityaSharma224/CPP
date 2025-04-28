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

Node* deleteNode(Node* head, int val){
    if(!head)return NULL;

    if(head->data == val){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* current = head;
    while(current->next && current->next->data != val){
        current = current->next;
    }

    if(current->next){
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    head = deleteNode(head, 2);

    printLL(head);
}