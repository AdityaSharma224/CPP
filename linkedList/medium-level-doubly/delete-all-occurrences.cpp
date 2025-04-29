#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data1, Node *next1 = NULL, Node *back1 = NULL)
    {
        data = data1;
        next = next1;
        back = back1;
    }
};

void printDL(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL\n";
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

Node* deleteAllOccurrences(Node *head, int target)
{
    // Delete nodes at the beginning if they match the target
    while (head != NULL && head->data == target)
    {
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->back = NULL;
        }
        delete temp;
    }

    // If head is null, return it
    if (head == NULL)
        return NULL;

    Node *current = head;
    while (current != NULL)
    {
        if (current->data == target)
        {
            // Node to be deleted is found
            Node *temp = current;
            current = current->next;

            if (temp->back != NULL)
            {
                temp->back->next = current;
            }
            if (current != NULL)
            {
                current->back = temp->back;
            }
            delete temp;
        }
        else
        {
            current = current->next;
        }
    }
    return head;
}

int main()
{
    Node *head = new Node(1);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 3);
    head = insertAtTail(head, 4);

    cout << "Original List: ";
    printDL(head);

    head = deleteAllOccurrences(head, 3);

    cout << "List after deletion: ";
    printDL(head);

    return 0;
}