#include<iostream>
#include "linked_list_class.cpp"
using namespace std;

Node* takeInput(){
    int data = 0;
    Node* head = NULL;
    Node* tail = NULL;
    cin>>data;
    while(data != -1){
        // Node n(data); //wrong because when the while loop completes variable n will be removed from the memory, hence linked list would be deleted
        Node* n = new Node(data);
        if(head == NULL){
            head = n;
            tail = head;
        }else{
        
            tail -> next = n;
            tail = tail -> next;
        }
        cin>>data;
    }
    return head;
}

void print_Linked_List(Node* head){
    while (head != NULL)
    {
        cout<<head -> data <<" ";
        head = head -> next;
    }
    cout<<endl;
}

Node*  mergeTwoSortedList(Node* h1, Node* h2){
    Node* hf = NULL;
    Node* tf = NULL;
    
    if(h1->data < h2->data){
        hf = h1;
        tf = h1;
        h1 = h1->next;
    }else{
        hf = h2;
        tf = h2;
        h2 = h2->next;
    }

    while(h1 != NULL  || h2 != NULL){
        while(h1 != NULL && h2 != NULL){
            if(h1->data < h2->data){
                tf->next = h1;
                tf = h1;
                h1 = h1->next;
            }else{
                tf->next = h2;
                tf = h2;
                h2 = h2->next;
            }
        }
        if(h1 != NULL){
            tf->next = h1;
            tf = h1;
            h1 = h1->next;
        }else if(h2 != NULL){
            tf->next = h2;
            tf = h2;
            h2 = h2->next;
        }
    }
    return hf;
}

int main(){

    Node* head1 = takeInput();
    
    print_Linked_List(head1);

    Node* head2 = takeInput();
    
    print_Linked_List(head2);

    Node* headf = mergeTwoSortedList(head1, head2);
    
    print_Linked_List(headf);

    return 0;
}
