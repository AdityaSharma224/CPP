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

// Brute force
int lengthOfLoop(Node* head){
    unordered_map<Node*,int>mp;
    Node* temp = head;
    int count=0;
    while(temp!=NULL){
        if(mp.find(temp)!=mp.end()){
            int loopLength = count - mp[temp];
            return loopLength;
        }
        mp[temp] = count;
        temp=temp->next;
        count++;
    }
    return count;
}

int findLength(Node* slow, Node* fast){
    int count=1;
    fast=fast->next;

    while(fast!=slow){
        count++;
        fast=fast->next;
    }
    return count;
}

int lengthOfLoop2(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;

        if(slow==fast){
            return findLength(slow,fast);
        }
    }
    return 0;
    
}


int main()
{
   
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);
    Node* fifth = new Node(5);

    // Create a loop from
    // fifth to second
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    
    // This creates a loop
    fifth->next = second; 

    int loopLength = lengthOfLoop2(head);
    if (loopLength > 0) {
        cout << "Length of the loop: " << loopLength << endl;
    } else {
        cout << "No loop found in the linked list." << endl;
    }

    return 0;
   
}