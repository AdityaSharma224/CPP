#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = NULL) {
        data = data1;
        next = next1;
    }
};

void printLL(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL) cout << "->";
        head = head->next;
    }
    cout << "->NULL" << endl;
}

// brute force
bool checkPalindroime(Node* head){
    stack<int>st;
    Node* temp = head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(!st.empty()){
        if(temp->data!=st.top()){
            return false;
        }
        st.pop();
        temp=temp->next;
    }
    return true;
}

// optimized

Node* reverseLinkedList(Node* head){
    if(!head || !head->next)return head;

    Node* newHead = reverseLinkedList(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

bool checkpalindrome(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }

    Node* newhead = reverseLinkedList(slow->next);
    Node* first = head;
    Node* second = newhead;

    while(second!=NULL){
        if(first->data != second->data){
            reverseLinkedList(newhead);
            return false;
        }
        first=first->next;
        second=second->next;
    }

    reverseLinkedList(newhead);
    return true;
}


int main() {
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(1);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);

    bool ans = checkpalindrome(head);
    cout<<ans;

    return 0;
}
