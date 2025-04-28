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

Node* sort012LL(Node* head){
    if(!head || !head->next) return head;

    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    Node* temp = head;

    while(temp!=NULL){
        if(temp->data == 0)count0++;
        else if(temp->data == 1)count1++;
        else if(temp->data == 2)count2++;
        temp=temp->next;
    }

    temp = head;
    while(count0--){
        temp->data = 0;
        temp=temp->next;
    }

    while(count1--){
        temp->data = 1;
        temp=temp->next;
    }

    while(count2--){
        temp->data = 2;
        temp=temp->next;
    }

    return head;
}


int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(0);
    head1->next->next->next = new Node(2);
    head1->next->next->next->next = new Node(1);
    
    Node* res = sort012LL(head1);
    printLL(res);
   
}