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

Node* reverseList(Node* head){
    if(!head || !head->next)return head;

    Node* newHead = reverseList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
};

Node* addOne(Node* head){
    if(head==NULL) return new Node(1);

    head = reverseList(head);
    Node* temp = head;
    int carry = 1;

    while(temp!=NULL){
        int sum = temp->data+carry;
        temp->data = sum%10;
        carry = sum/10;

        if(carry==0)break;

        if(temp->next==NULL && carry !=0){
            temp->next = new Node(0);
        }
        temp=temp->next;
    }
    head = reverseList(head);

    return head;
}

int main()
{
    Node *head1 = new Node(7);
    head1->next = new Node(2);
    head1->next->next = new Node(9);
    
    Node* res = addOne(head1);
    printLL(res);
   
}