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
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << endl;
};

Node* segrregateList(Node* head1){
    if(!head1 || !head1->next)return head1;

    Node* odd = head1;
    Node* even = head1->next;
    Node* evenStart = even;

    while(odd->next!=NULL && even->next!=NULL){
        odd->next = even->next;
        odd=odd->next;
        even->next = odd->next;
        even=even->next;
    }
    odd->next = evenStart;
    return head1;

}


int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    Node *head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);
    
    printLL(segrregateList(head1));
   
}