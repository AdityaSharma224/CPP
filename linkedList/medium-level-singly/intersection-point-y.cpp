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
        cout << head->data;
        if (head->next != NULL)
            cout << "->";
        head = head->next;
    }
    cout << endl;
};

Node *intersectionPoint(Node *head1, Node *head2)
{
    Node *d1 = head1;
    Node *d2 = head2;
    while (d1 != d2)
    {
        d1 = (d1 == NULL) ? head2 : d1->next;
        d2 = (d2 == NULL) ? head1 : d2->next;
    }
    return d1;
}

int main()
{
    Node* common = new Node(2);
    common->next = new Node(4);

    Node* head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(1);
    head1->next->next->next = common; // linking to common part

    Node* head2 = new Node(3);
    head2->next = common; // linking to common part

    Node* res = intersectionPoint(head1, head2);
    if (res)
        cout << "Intersection at node with value: " << res->data << endl;
    else
        cout << "No intersection found!" << endl;
    
    // Optional: printing from intersection node
    printLL(res);

    return 0;
}