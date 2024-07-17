#include <iostream>

using namespace std;

class Node{
  public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = NULL;
    }
};
void print_list(Node* n){
        while(n!=NULL){
            cout<<n->data<<" ";
            n = n->next;
        }
        cout<<endl;
}
//<-------------------------------------------------TAKING INPUT------------------------------------------------------------->
Node* takeinput(int n){
    int val;
    cin>>val;
    Node* head = new Node(val);
    Node* temp = head;
    for(int i = 0;i<n;i++){
        cin>>val;
        temp->next = new Node(val);
        temp = temp->next;
    }
    return head;
}
//<-------------------------------------------INSERT A NODE IN A LINKED LIST------------------------------------------------>
void insert_at_end(Node** head,int a){
    Node* newnode = new Node(a);
    Node* last = *head;
    newnode->next = NULL;
    if(*head== NULL){
        *head = newnode;
        return;
    }
    while(last->next!=NULL){
        last = last->next;
    }
    last->next = newnode;
    return;
}

void insert_at_beginning(Node** head,int a){
    Node* newnode = new Node(a);
    newnode->next= *head;
    *head = newnode;
}

void insert_after(Node* prev_node,int a){
    Node* newnode = new Node(a);
    newnode->next = prev_node->next;
    prev_node->next = newnode;
    
}
//<-------------------------------------------DELETE A NODE IN A LINKED LIST------------------------------------------>
Node* deleteNode(Node* head, int position) {
    Node* temp =head;
    for(int i=0;i<position-1;i++){
        temp =temp->next;
    }
    if(position==0){
        Node* temp2 = head;
        temp = head->next;
        delete(temp2);
        return temp;
    }
    temp->next = temp->next->next;
    return head;
}

//<--------------------------------------------REVERSE A LINKED LIST------------------------------------------------------>
Node* reverse(Node* head) {
    if(head == NULL){
        return head;
    }
    Node* curr = head;
    Node* prev = NULL;
    Node* forward = curr->next;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev= curr;
        curr=forward;
    }
    head = prev;
    return prev;
}


int main() {
    int n,val;
    cin>>n;

    Node* head = NULL;
    for(int i=0;i<n;i++){
        cin>>val;
        Node* newNode=new Node(val);
        if(head==NULL){
            head = newNode;
        }else{
            Node* temp = head;
            while(temp->next!=NULL){
                temp = temp ->next;
            }
             temp->next= newNode;
        }
    }
    cout<<"Linked list:"<<endl;
    print_list(head);
    insert_at_end(&head,4);
    cout<<"New linked list after inserting at end :"<<endl;
    print_list(head);
    insert_at_beginning(&head,0);
    cout<<"New linked list after inserting at the beginning :"<<endl;
    print_list(head);
    cout<<"New linked list after inserting in between :"<<endl;
    insert_after(head->next->next,5);
    print_list(head);
    
    return 0;
}
