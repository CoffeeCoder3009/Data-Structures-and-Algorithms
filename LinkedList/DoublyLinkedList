#include<iostream>

using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};
void print_list(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
    }
    cout<<endl;
}
//<------------------------------------INSERT IN A DOUBLY LINKED LIST-------------------------------------------------->
void insert_at_head(node* head,int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_at_tail(node* head,int val){
    node* newnode = new node(val);
    if(head == NULL){
        head = newnode;
        return;
    }
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = newnode;
    newnode->prev = temp;
}

void addNode(node *head, int pos, int data)
{
    
    node* newnode = new node(data);
    if(head == NULL){
        head = newnode;
        return;
    }
    if(pos == 0){
            insert_at_head(head, data);
            return;
    }
   
    node* temp = head;
    int cnt = 0;
    while(temp != NULL && cnt < pos-1){
        temp = temp->next;
        cnt++;
    }
    
    if(temp->next == NULL){
        insert_at_tail(head,data);
        return;
    }
    
    newnode->next = temp->next;
    temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

//<------------------------------------DELETE IN A DOUBLY LINKED LIST-------------------------------------------------->
node* deleteNode(node* head, int pos) {
    if (head == NULL) {
        return NULL;
    }

    // deleting the head node
    if (pos == 1) {
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        return head;
    }

    node* curr = head;
    int cnt = 1;
    while (curr != NULL && cnt < pos) {
        curr = curr->next;
        cnt++;
    }

    // If position is out of bounds
    if (curr == NULL) {
        return head;
    }
    
    if (curr->next != NULL) {
        curr->next->prev = curr->prev;
    }
    if (curr->prev != NULL) {
        curr->prev->next = curr->next;
    }

    delete curr;
    return head;
}
//<------------------------------------SORTED INSERT IN DOUBLY LINKED LIST--------------------------------------------->
node* sortedInsert(node* head, int data) {
    node* newnode = new node(data);
    if(head==NULL){
        return newnode;
    }
    if(data < head->data){
        newnode->next=head;
        head->prev=newnode;
        return newnode;
    }
    node* temp= head;
    while(temp->next!=NULL && temp->next->data < data){
        temp = temp->next;
    }
    newnode->prev = temp;
    newnode->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = newnode;
    }
    temp->next = newnode;
    return head;
}

//<------------------------------------REVERSE A DOUBLY LINKED LIST-------------------------------------------------->
node* reverse(node* head) {
    if (head == NULL) {
        return NULL;
    }
    node* ptr1 = head;
    node* ptr2 = ptr1->next;
    ptr1->next = NULL;
    ptr1->prev = ptr2;
    while (ptr2 != NULL) {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}
