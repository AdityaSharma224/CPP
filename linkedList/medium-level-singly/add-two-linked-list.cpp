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


Node* addTwoList(Node* head1, Node* head2){
    Node* dummy = new Node(0);
    Node* temp = dummy;
    int carry = 0;

    while(head1!=NULL || head2!=NULL || carry!=0){
        int sum = carry;

        if(head1!=NULL){
            sum+=head1->data;
            head1=head1->next;
        }

        if(head2!=NULL){
            sum+=head2->data;
            head2=head2->next;
        }

        carry = sum/10;
        Node* newNode = new Node(sum%10);
        temp->next = newNode;
        temp=temp->next;
    }
    return dummy->next;
}


int main()
{
    Node *head1 = new Node(7);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    Node *head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);
    
    Node* res = addTwoList(head1,head2);
    printLL(res);
   
}